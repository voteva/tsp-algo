#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct
{
    unsigned int size;
    int **distances;
} Graph;

Graph *initGraph(char *fileName);

Graph *copyGraph(Graph *graph);

void printGraph(Graph *graph);

#endif
