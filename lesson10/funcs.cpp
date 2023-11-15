#include <iostream>
#include <climits>
#include "header.h"

using namespace std;

int findMinDistance(int distances[], bool visited[], int size) {
    int minDistance = INT_MAX, minIndex;

    for (int i = 0; i < size; i++) {
        if (!visited[i] && distances[i] <= minDistance) {
            minDistance = distances[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printSolution(int distances[], int size) {
    cout << "Vertex \t Distance from the source\n";
    for (int i = 0; i < size; i++)
        cout << i + 1 << " \t\t " << distances[i] << "\n";
}

void dijkstra(int graph[V][V], int source, int size) {
    int distances[size];
    bool visited[size];

    for (int i = 0; i < size; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    distances[source] = 0;
    for (int count = 0; count < size - 1; count++) {
        int u = findMinDistance(distances, visited);
        visited[u] = true;

        for (int v = 0; v < size; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
    printSolution(distances);
}
