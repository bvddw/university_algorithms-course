#ifndef INDIVIDUAL_TASK_GRAPH_H
#define INDIVIDUAL_TASK_GRAPH_H


class Graph {
private:
    int vertices;
    int** edges;

public:
    Graph(int v);

    void addEdge(int from, int to);

    void printGraph();

    void saveGraph();

    void removeTriangle(int v1, int v2, int v3);

    bool hasTriangles();

    void eliminateTriangles();

    ~Graph();
};

#endif