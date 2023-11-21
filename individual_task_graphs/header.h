#ifndef INDIVIDUAL_TASK_GRAPH_H
#define INDIVIDUAL_TASK_GRAPH_H

/*
Трикутником графа назвемо будь-яку трійку різних і попарно
суміжних вершин цього графа. Склеюванням трикутника
назвемо таку операцію: три вершини, що становлять трикутник,
видаляються з графа разом з усіма інцидентними їм ребрами;
додається нова вершина v, а ребро <w, v> додається тоді і лише
тоді, коли вершина w була суміжна хоча б з однією вершиною
віддаленого трикутника. Послідовним застосуванням операції
склеювання трикутника перетворити вихідний граф на такий, у
якому немає трикутників.
*/

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