#include "Graph.h"
#include <iostream>
using namespace std;

int main()
{
    Graph g(6); 

    g.addEdge(0, 2, 28); 
    g.addEdge(0, 4, 7);  
    g.addEdge(0, 3, 19); 
    g.addEdge(0, 5, 15); 
    g.addEdge(3, 4, 20); 
    g.addEdge(3, 1, 21); 
    g.addEdge(1, 5, 24); 
    g.addEdge(4, 5, 16); 
    g.addEdge(5, 3, 31); 
    g.addEdge(4, 3, 14); 
    g.addEdge(2, 3, 39); 
    g.addEdge(2, 4, 30); 
    g.addEdge(3, 2, 12); 

    int choice;
    while (true) {
        cout << "\nChoice:\n"
            << "1. BFS\n"
            << "2. DFS\n"
            << "3. Dijkstra's algorithm\n"
            << "4. Floyd's Algorithm\n"
            << "5. Distance matrix\n"
            << "6. Adjacency matrix\n"
            << "7. Add a vertex\n"
            << "8. Delete a vertex\n"
            << "9. Add an edge\n"
            << "10. Delete an edge\n"
            << "11. Change the edge weight\n"
            << "0. Exit\n"
            << "Enter: ";
        cin >> choice;

        if (choice == 0) break;

        int u, v, w;
        switch (choice) {
        case 1:
            cout << "The initial vertex (1-6): "; cin >> u;
            g.BFS(u - 1);
            break;
        case 2:
            cout << "The initial vertex (1-6): "; cin >> u;
            g.DFS(u - 1);
            break;
        case 3:
            cout << "The initial vertex (1-6): "; cin >> u;
            g.dijkstra(u - 1);
            break;
        case 4:
            g.floydWarshall();
            break;
        case 5:
            g.printDistanceMatrix();
            break;
        case 6:
            g.printAdjacencyMatrix();
            break;
        case 7:
            g.addVertex();
            break;
        case 8:
            cout << "Delete a vertex (1-6): "; cin >> u;
            g.removeVertex(u - 1);
            break;
        case 9:
            cout << "An edge from (1-6): "; cin >> u;
            cout << "Where (1-6): "; cin >> v;
            cout << "Weight: "; cin >> w;
            g.addEdge(u - 1, v - 1, w);
            break;
        case 10:
            cout << "Remove an edge from (1-6): "; cin >> u;
            cout << "Where (1-6): "; cin >> v;
            g.removeEdge(u - 1, v - 1);
            break;
        case 11:
            cout << "An edge from (1-6): "; cin >> u;
            cout << "Where (1-6): "; cin >> v;
            cout << "New weight: "; cin >> w;
            g.changeWeight(u - 1, v - 1, w);
            break;
        default:
            cout << "Error\n";
        }
    }

    return 0;
}