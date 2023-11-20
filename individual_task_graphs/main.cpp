#include "funcs.cpp"

using namespace std;

int main() {
    int adjacencyMatrix[12][12] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };

    Graph myGraph(12);

    // Заповнення графу за допомогою матриці суміжності
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                myGraph.addEdge(i, j);
            }
        }
    }

    cout << "Original Graph:" << endl;
    myGraph.printGraph();
    myGraph.saveGraph();

    myGraph.eliminateTriangles();

    cout << "\nGraph after eliminating triangles:" << endl;
    myGraph.printGraph();
    myGraph.saveGraph();

    return 0;
}