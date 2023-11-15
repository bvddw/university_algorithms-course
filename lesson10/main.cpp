#include <iostream>
#include "funcs.cpp"

#define V 6

int main() {
    // test 1
    int graph1[V][V] = { {0, 1, 4, 0, 0, 0},
                        {1, 0, 4, 2, 7, 0},
                        {4, 4, 0, 3, 5, 0},
                        {0, 2, 3, 0, 4, 6},
                        {0, 7, 5, 4, 0, 7},
                        {0, 0, 0, 6, 7, 0} };
    dijkstra(graph1, 3);

    // test 2 (from lesson)
    int graph2[V][V] = { {0, 3, 7, 0, 0, 0},
                        {1, 0, 2, 0, 0, 1},
                        {0, 1, 0, 2, 4, 0},
                        {0, 0, 0, 0, 1, 5},
                        {0, 0, 1, 0, 0, 3},
                        {0, 0, 0, 2, 0, 0} };

    dijkstra(graph2, 0);

    return 0;
}