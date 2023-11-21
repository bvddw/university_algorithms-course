#include <iostream>
#include "header.h"

using namespace std;

Graph::Graph(int vertices) : vertices(vertices) {
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new int[vertices];
    }
    
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            adjMatrix[i][j] = 0;
        }
    }
}

void Graph::addEdge(int src, int dest, int value) {
    adjMatrix[src][dest] = value;
}

void Graph::findAllPaths(int start, int end, bool* visited, int* path, int pathIndex) {
    visited[start] = true;
    path[pathIndex] = start;
    ++pathIndex;
    int sum;
    if (start == end) {
        sum = 0;
        for (int i = 0; i < pathIndex; ++i) {
            cout << path[i] + 1 << " ";
            if (i > 0) {
                sum = sum + adjMatrix[path[i - 1]][path[i]];
            }
        }
        cout << "Price of this way - " << sum << endl;
    } else {
        // Рекурсивно шукаємо шляхи з кожного сусіда
        for (int neighbor = 0; neighbor < vertices; ++neighbor) {
            if (adjMatrix[start][neighbor] && !visited[neighbor]) {
                findAllPaths(neighbor, end, visited, path, pathIndex);
            }
        }
    }

    // Позначаємо поточну вершину як невідвідану, щоб інші шляхи могли її використовувати
    visited[start] = false;
}

void Graph::printAllPaths(int start, int end) {
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    int* path = new int[vertices];
    int pathIndex = 0;

    cout << "All ways from " << start + 1 << " to " << end + 1 << ":" << endl;
    findAllPaths(start, end, visited, path, pathIndex);
}

Graph::~Graph() {
    for (int i = 0; i < vertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}