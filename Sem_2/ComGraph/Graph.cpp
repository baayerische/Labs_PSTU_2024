#include "Graph.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <climits>
#include <algorithm>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

const int N = 6;
int adjMatrix[N][N] = {
    {0,   INF, 28,  19,  7,   15}, 
    {INF, 0,   INF, INF, INF, 24}, 
    {INF, INF, 0,   39,  30,  INF},
    {21,  12,  INF, 0,   20,  INF},
    {INF, INF, INF, 14,  0,   16}, 
    {INF, INF, INF, 31,  INF, 0}   
};

int final_path[N + 1];
bool visited[N];
int final_res = INT_MAX;

// Проверка достижимости всех вершин из начальной точки
bool canReachAll(int start) {
    vector<bool> reachable(N, false);
    queue<int> q;
    q.push(start);
    reachable[start] = true;
    int count = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < N; v++) {
            if (adjMatrix[u][v] != INF && !reachable[v]) {
                reachable[v] = true;
                q.push(v);
                count++;
            }
        }
    }
    return count == N;
}

void copyToFinal(int curr_path[]) {
    for (int i = 0; i < N; i++)
        final_path[i] = curr_path[i];
    final_path[N] = curr_path[0];
}

int firstMin(int i) {
    int min = INT_MAX;
    for (int k = 0; k < N; k++)
        if (adjMatrix[i][k] < min && i != k)
            min = adjMatrix[i][k];
    return min == INT_MAX ? INF : min;
}

int secondMin(int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (i == j) continue;

        if (adjMatrix[i][j] <= first) {
            second = first;
            first = adjMatrix[i][j];
        }
        else if (adjMatrix[i][j] <= second && adjMatrix[i][j] != first)
            second = adjMatrix[i][j];
    }
    return second == INT_MAX ? INF : second;
}

void TSPRec(int curr_bound, int curr_weight, int level, int curr_path[]) {
    if (level == N) {
        if (adjMatrix[curr_path[level - 1]][curr_path[0]] != INF) {
            int curr_res = curr_weight + adjMatrix[curr_path[level - 1]][curr_path[0]];
            if (curr_res < final_res) {
                copyToFinal(curr_path);
                final_res = curr_res;
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (adjMatrix[curr_path[level - 1]][i] != INF && !visited[i]) {
            int temp = curr_bound;
            curr_weight += adjMatrix[curr_path[level - 1]][i];

            if (level == 1)
                curr_bound -= (firstMin(curr_path[level - 1]) + firstMin(i)) / 2;
            else
                curr_bound -= (secondMin(curr_path[level - 1]) + firstMin(i)) / 2;

            if (curr_bound + curr_weight < final_res) {
                curr_path[level] = i;
                visited[i] = true;
                TSPRec(curr_bound, curr_weight, level + 1, curr_path);
            }

            curr_weight -= adjMatrix[curr_path[level - 1]][i];
            curr_bound = temp;

            fill(visited, visited + N, false);
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

void TSP() {
    int curr_path[N + 1];
    int curr_bound = 0;
    fill(curr_path, curr_path + N + 1, -1);
    fill(visited, visited + N, false);

    // Проверка достижимости всех вершин из начальной (0)
    if (!canReachAll(0)) {
        cout << "TSP: Невозможно построить гамильтонов цикл, так как не все вершины достижимы из начальной точки.\n";
        final_res = -1;
        return;
    }

    for (int i = 0; i < N; i++) {
        int fm = firstMin(i);
        int sm = secondMin(i);
        if (fm != INF && sm != INF)
            curr_bound += (fm + sm);
    }

    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

    visited[0] = true;
    curr_path[0] = 0;

    TSPRec(curr_bound, 0, 1, curr_path);
}

int main() {
    setlocale(LC_ALL, "ru");

    // Загрузка шрифта
    sf::Font font;
    const std::string fontPaths[] = {
        "arial.ttf",
        "fonts/arial.ttf",
        "C:/Windows/Fonts/arial.ttf"
    };

    bool fontLoaded = false;
    for (const auto& path : fontPaths) {
        if (font.loadFromFile(path)) {
            fontLoaded = true;
            break;
        }
    }

    if (!fontLoaded) {
        cout << "Ошибка: не удалось загрузить шрифт\n";
    }

    RenderWindow window(VideoMode(800, 600), "Graph Visualizer");
    window.setFramerateLimit(60);

    Graph graph(true);
    for (int i = 1; i <= 6; i++) graph.InsertVertex(i);

    graph.InsertEdge(1, 3, 28); 
    graph.InsertEdge(1, 5, 7);  
    graph.InsertEdge(1, 4, 19); 
    graph.InsertEdge(1, 6, 15); 
    graph.InsertEdge(4, 5, 20); 
    graph.InsertEdge(4, 2, 21); 
    graph.InsertEdge(2, 6, 24); 
    graph.InsertEdge(5, 6, 16); 
    graph.InsertEdge(6, 4, 31); 
    graph.InsertEdge(5, 4, 14); 
    graph.InsertEdge(3, 4, 39); 
    graph.InsertEdge(3, 5, 30); 
    graph.InsertEdge(4, 2, 12);

    vector<int> bfsResult, dfsResult;
    graph.BFS(6, bfsResult);
    graph.DFS(6, dfsResult);
    auto dijkstraResult = graph.Dijkstra(6);

    cout << "Обход графа в ширину с 6: ";
    for (int v : bfsResult) cout << v << " ";
    cout << endl;

    cout << "Обход графа в глубину с 6: ";
    for (int v : dfsResult) cout << v << " ";
    cout << endl;

    cout << "Кратчайшие расстояния по алгоритму Дейкстры из вершины 6:" << endl;
    auto vertices = graph.getVertices();
    for (size_t i = 0; i < dijkstraResult.size(); i++) {
        cout << "К " << vertices[i] << ": " << (dijkstraResult[i] == INF ? "INF" : to_string(dijkstraResult[i])) << endl;
    }

    TSP();

    if (final_res != -1) {
        cout << "Минимальная стоимость: " << final_res << endl;
        cout << "Оптимальный путь: ";
        for (int i = 0; i <= N; i++)
            cout << final_path[i] + 1 << " ";
        cout << endl;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color::White);
        graph.DrawGraph(window);

        if (fontLoaded) {
            sf::Text text;
            text.setFont(font);
            text.setString("Solution to the traveling salesman problem");
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(20, 20);
            window.draw(text);
        }

        window.display();
    }

    return 0;
}