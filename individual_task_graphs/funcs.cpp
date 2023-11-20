#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

Graph::Graph(int v) : vertices(v) {
    const char* filename = "graph.txt";
    ofstream file(filename, ios::trunc);

    edges = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        edges[i] = new int[vertices];
    }
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            edges[i][j] = 0;
        }
    }
}

void Graph::addEdge(int from, int to) {
    edges[from][to] = 1;
    edges[to][from] = 1;
}

void Graph::printGraph() {
    for (int i = 0; i < vertices; ++i) {
        cout << "Adjacent vertices to vertex " << i + 1 << ": ";
        for (int j = 0; j < vertices; ++j) {
            if (edges[i][j] == 1) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}

void Graph::saveGraph() {
    const char* filename = "graph.txt";
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error with opening file 'graph.txt'." << endl;
    }
    for (int i = 0; i < vertices; ++i) {
        file << "Adjacent vertices to vertex " << i + 1 << ": ";
        for (int j = 0; j < vertices; ++j) {
            if (edges[i][j] == 1) {
                file << j + 1 << " ";
            }
        }
        file << endl;
    }
    file << endl;
}

void Graph::removeTriangle(int v1, int v2, int v3) {
    int** newEdges = new int*[vertices - 2];
    int current_index_1 = 0;
    int current_index_2 = 0;
    for (int i = 0; i < vertices; i++) {
        if (i == v1 || i == v2 || i == v3) {
            continue;
        }
        newEdges[current_index_1] = new int[vertices - 2];
        current_index_2 = 0;
        for (int j = 0; j < vertices; j++) {
            if (j == v1 || j == v2 || j == v3) {
                continue;
            }
            newEdges[current_index_1][current_index_2] = edges[i][j];
            current_index_2++;
        }
        newEdges[current_index_1][current_index_2] = edges[i][v1] || edges[i][v2] || edges[i][v3];
        current_index_1++;
    }
    newEdges[current_index_1] = new int[vertices];
    for (int i = 0; i < vertices - 3; i++) {
        newEdges[current_index_1][i] = newEdges[i][current_index_1];
    }
    newEdges[current_index_1][current_index_1] = 0;
    for (int i = 0; i < vertices; i++) {
        delete[] edges[i];
    }

    edges = newEdges;
    vertices -= 2;
}

bool Graph::hasTriangles() {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            for (int k = 0; k < vertices; ++k) {
                if (edges[i][j] == 1 && edges[j][k] == 1 && edges[k][i] == 1) {
                    cout << endl << "Removing vertixes: " << i + 1 << ", " << j + 1 << ", " << k + 1 << endl;
                    removeTriangle(i, j, k);
                    printGraph();
                    saveGraph();
                    return true;
                }
            }
        }
    }
    return false;
}

void Graph::eliminateTriangles() {
    while (hasTriangles()) {}
}

Graph::~Graph() {
    for (int i = 0; i < vertices; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}