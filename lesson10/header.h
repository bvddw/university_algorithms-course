#ifndef LESSON10_HEADER_H
#define LESSON10_HEADER_H

#define V 6

int findMinDistance(int distances[], bool visited[], int size = V);
void printSolution(int distances[], int size = V);
void dijkstra(int graph[V][V], int source, int size = V);


#endif //LESSON10_HEADER_H
