#include "Graph.h"

Graph::Graph(int v) : V(v) {
    dist.resize(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i)
        dist[i][i] = 0;
}

void Graph::addEdge(int u, int v, int weight) {
    dist[u][v] = weight;
}

void Graph::removeEdge(int u, int v) {
    dist[u][v] = INF;
}

void Graph::changeWeight(int u, int v, int weight) {
    dist[u][v] = weight;
}

void Graph::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << (u + 1) << " ";

        for (int v = 0; v < V; ++v) {
            if (dist[u][v] != INF && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << (v + 1) << " ";
    for (int u = 0; u < V; ++u) {
        if (dist[v][u] != INF && !visited[u])
            DFSUtil(u, visited);
    }
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    cout << "DFS: ";
    DFSUtil(start, visited);
    cout << endl;
}

void Graph::dijkstra(int src) {
    vector<int> distance(V, INF);
    set<pair<int, int>> s;
    distance[src] = 0;
    s.insert({0, src});

    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());

        for (int v = 0; v < V; ++v) {
            if (dist[u][v] != INF) {
                if (distance[u] + dist[u][v] < distance[v]) {
                    s.erase({distance[v], v});
                    distance[v] = distance[u] + dist[u][v];
                    s.insert({distance[v], v});
                }
            }
        }
    }

    cout << "Dijkstra from the top " << src + 1 << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "  До " << (i + 1) << ": " << (distance[i] == INF ? -1 : distance[i]) << endl;
}

void Graph::floydWarshall() {
    vector<vector<int>> fw = dist;
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (fw[i][k] + fw[k][j] < fw[i][j])
                    fw[i][j] = fw[i][k] + fw[k][j];

    cout << "The matrix of shortest distances:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (fw[i][j] == INF) cout << "INF ";
            else cout << fw[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::printDistanceMatrix() {
    cout << "The distance matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::printAdjacencyMatrix() {
    cout << "The adjacency matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << (dist[i][j] != INF ? 1 : 0) << " ";
        }
        cout << endl;
    }
}

void Graph::addVertex() {
    ++V;
    for (auto& row : dist) {
        row.push_back(INF);
    }
    dist.push_back(vector<int>(V, INF));
    dist[V - 1][V - 1] = 0;
    cout << "The vertex has been added. Now " << V << " vertexes.\n";
}

void Graph::removeVertex(int vertex) {
    if (vertex < 0 || vertex >= V) {
        cout << "Incorrect vertex.\n";
        return;
    }
    dist.erase(dist.begin() + vertex);
    for (auto& row : dist)
        row.erase(row.begin() + vertex);
    --V;
    cout << "The vertex has been deleted. Now " << V << " vertexes.\n";
}
