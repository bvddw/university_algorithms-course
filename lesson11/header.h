class Graph {
private:
    int vertices;
    int** adjMatrix;
    
public:
    Graph(int vertices);

    void addEdge(int src, int dest, int value);

    void findAllPaths(int start, int end, bool* visited, int* path, int pathIndex);

    void printAllPaths(int start, int end);

    ~Graph();
};