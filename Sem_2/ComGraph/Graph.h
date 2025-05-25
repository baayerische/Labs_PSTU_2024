#pragma once
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;
    vector<int> vertices;
    bool isDirected;

public:
    Graph(bool directed = false) : isDirected(directed) {}

    void InsertVertex(int v) {
        if (find(vertices.begin(), vertices.end(), v) == vertices.end()) {
            vertices.push_back(v);
            adjList.resize(vertices.size());
        }
    }

    void RemoveVertex(int v) {
        auto it = find(vertices.begin(), vertices.end(), v);
        if (it != vertices.end()) {
            int idx = distance(vertices.begin(), it);
            vertices.erase(it);
            adjList.erase(adjList.begin() + idx);

            for (auto& edges : adjList) {
                edges.erase(
                    remove_if(edges.begin(), edges.end(),
                        [v](const pair<int, int>& p) { return p.first == v; }),
                    edges.end()
                );
            }
        }
    }

    void InsertEdge(int v1, int v2, int weight) {
        auto it1 = find(vertices.begin(), vertices.end(), v1);
        auto it2 = find(vertices.begin(), vertices.end(), v2);

        if (it1 == vertices.end() || it2 == vertices.end()) {
            cout << "Error: Vertex " << (it1 == vertices.end() ? v1 : v2) << " does not exist\n";
            return;
        }

        int idx1 = distance(vertices.begin(), it1);
        int idx2 = distance(vertices.begin(), it2);

        adjList[idx1].emplace_back(v2, weight);
        if (!isDirected) {
            adjList[idx2].emplace_back(v1, weight);
        }
    }

    void RemoveEdge(int v1, int v2) {
        auto it1 = find(vertices.begin(), vertices.end(), v1);
        auto it2 = find(vertices.begin(), vertices.end(), v2);

        if (it1 != vertices.end() && it2 != vertices.end()) {
            int idx1 = distance(vertices.begin(), it1);
            int idx2 = distance(vertices.begin(), it2);

            adjList[idx1].erase(
                remove_if(adjList[idx1].begin(), adjList[idx1].end(),
                    [v2](const pair<int, int>& p) { return p.first == v2; }),
                adjList[idx1].end()
            );

            if (!isDirected) {
                adjList[idx2].erase(
                    remove_if(adjList[idx2].begin(), adjList[idx2].end(),
                        [v1](const pair<int, int>& p) { return p.first == v1; }),
                    adjList[idx2].end()
                );
            }
        }
    }

    void BFS(int start, vector<int>& traversal) {
        vector<bool> visited(vertices.size(), false);
        queue<int> q;

        auto it = find(vertices.begin(), vertices.end(), start);
        if (it == vertices.end()) return;

        int startIdx = distance(vertices.begin(), it);
        q.push(startIdx);
        visited[startIdx] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            traversal.push_back(vertices[current]);

            for (auto& neighbor : adjList[current]) {
                auto neighborIt = find(vertices.begin(), vertices.end(), neighbor.first);
                int neighborIdx = distance(vertices.begin(), neighborIt);
                if (!visited[neighborIdx]) {
                    visited[neighborIdx] = true;
                    q.push(neighborIdx);
                }
            }
        }
    }

    void DFS(int start, vector<int>& traversal) {
        vector<bool> visited(vertices.size(), false);
        stack<int> s;

        auto it = find(vertices.begin(), vertices.end(), start);
        if (it == vertices.end()) return;

        int startIdx = distance(vertices.begin(), it);
        s.push(startIdx);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                traversal.push_back(vertices[current]);

                for (auto& neighbor : adjList[current]) {
                    auto neighborIt = find(vertices.begin(), vertices.end(), neighbor.first);
                    int neighborIdx = distance(vertices.begin(), neighborIt);
                    if (!visited[neighborIdx]) {
                        s.push(neighborIdx);
                    }
                }
            }
        }
    }

    vector<int> Dijkstra(int start) {
        vector<int> dist(vertices.size(), INF);
        vector<bool> visited(vertices.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        auto it = find(vertices.begin(), vertices.end(), start);
        if (it == vertices.end()) return dist;

        int startIdx = distance(vertices.begin(), it);
        dist[startIdx] = 0;
        pq.emplace(0, startIdx);

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (auto& neighbor : adjList[u]) {
                auto vIt = find(vertices.begin(), vertices.end(), neighbor.first);
                int v = distance(vertices.begin(), vIt);
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist;
    }

    vector<int> getVertices() const {
        return vertices;
    }

    void DrawGraph(RenderWindow& window) {
        vector<Vector2f> positions;
        float radius = 200.f;
        Vector2f center(400.f, 300.f);
        float angle = 0.f;
        float angleStep = 2 * 3.14159f / vertices.size();

        Font font;
        if (!font.loadFromFile("arial.ttf")) return;

        // Расположение вершин по кругу
        for (size_t i = 0; i < vertices.size(); ++i) {
            positions.emplace_back(
                center.x + radius * cos(angle),
                center.y + radius * sin(angle)
            );
            angle += angleStep;
        }

        // Отрисовка ребер
        for (size_t i = 0; i < adjList.size(); ++i) {
            for (auto& neighbor : adjList[i]) {
                auto it = find(vertices.begin(), vertices.end(), neighbor.first);
                int j = distance(vertices.begin(), it);

                Vector2f startPos = positions[i];
                Vector2f endPos = positions[j];
                Vector2f direction = endPos - startPos;
                float length = sqrt(direction.x * direction.x + direction.y * direction.y);
                direction /= length;

                // сокращение линии, чтобы она не заходила внутрь вершин
                startPos += direction * 20.f;
                endPos -= direction * 20.f;

                // Отрисовка линии
                Vertex line[] = {
                    Vertex(startPos, Color::Black),
                    Vertex(endPos, Color::Black)
                };
                window.draw(line, 2, Lines);

                // Отрисовка стрелки (для направленного графа)
                if (isDirected) {
                    Vector2f arrowDir = endPos - startPos;
                    float arrowLength = 10.f;
                    float arrowAngle = 30.f * 3.14159f / 180.f;

                    Vector2f arrowPoint1 = endPos - arrowDir * (arrowLength / length) +
                        Vector2f(-arrowDir.y, arrowDir.x) * tan(arrowAngle) * arrowLength / length;
                    Vector2f arrowPoint2 = endPos - arrowDir * (arrowLength / length) +
                        Vector2f(arrowDir.y, -arrowDir.x) * tan(arrowAngle) * arrowLength / length;

                    Vertex arrow[] = {
                        Vertex(endPos, Color::Black),
                        Vertex(arrowPoint1, Color::Black),
                        Vertex(endPos, Color::Black),
                        Vertex(arrowPoint2, Color::Black)
                    };
                    window.draw(arrow, 4, Lines);
                }

                // Отрисовка веса ребра
                Text weightText;
                weightText.setFont(font);
                weightText.setString(to_string(neighbor.second));
                weightText.setCharacterSize(12);
                weightText.setFillColor(Color::Red);
                weightText.setPosition(
                    (startPos.x + endPos.x) / 2,
                    (startPos.y + endPos.y) / 2
                );
                window.draw(weightText);
            }
        }

        // Отрисовка вершин
        for (size_t i = 0; i < positions.size(); ++i) {
            CircleShape circle(20.f);
            circle.setPosition(positions[i].x - 20, positions[i].y - 20);
            circle.setFillColor(Color::Blue);
            window.draw(circle);

            Text vertexText;
            vertexText.setFont(font);
            vertexText.setString(to_string(vertices[i]));
            vertexText.setCharacterSize(14);
            vertexText.setFillColor(Color::White);
            vertexText.setPosition(positions[i].x - 5, positions[i].y - 8);
            window.draw(vertexText);
        }
    }
};