#include <iostream>
#include "funcs.cpp"

using namespace std;

int main() {
    cout << "EXAMPLE 1\n";
    int verticies_1 = 6;
    Graph* graph1 = new Graph(verticies_1);
    int adjacencyMatrix1[verticies_1][verticies_1] = {
        {0, 3, 7, 0, 0, 0},
        {1, 0, 2, 0, 0, 1},
        {0, 2, 0, 2, 4, 0},
        {0, 0, 0, 0, 1, 5},
        {0, 0, 1, 0, 0, 3},
        {0, 0, 0, 2, 0, 0}
    };

    for (int i = 0; i < verticies_1; i++) {
        for (int j = 0; j < verticies_1; j++) {
            if (adjacencyMatrix1[i][j]) {
                graph1->addEdge(i, j, adjacencyMatrix1[i][j]);
            }
        }
    }

    int startVertex1 = 1;
    int endVertex1 = 4;

    graph1->printAllPaths(startVertex1, endVertex1);

    cout << "\nEXAMPLE 2:\n";

    int verticies_2 = 6;
    Graph* graph2 = new Graph(verticies_2);
    int adjacencyMatrix2[verticies_2][verticies_2] = {
        {0, 3, 5, 0, 0, 0},
        {2, 0, 4, 6, 0, 0},
        {1, 2, 0, 8, 7, 0},
        {0, 1, 2, 0, 0, 9},
        {0, 0, 1, 0, 0, 8},
        {0, 0, 0, 4, 5, 0},
    };

    for (int i = 0; i < verticies_2; i++) {
        for (int j = 0; j < verticies_2; j++) {
            if (adjacencyMatrix2[i][j]) {
                graph2->addEdge(i, j, adjacencyMatrix2[i][j]);
            }
        }
    }

    int startVertex2 = 0;
    int endVertex2 = 1;

    graph2->printAllPaths(startVertex2, endVertex2);

    return 0;
}
