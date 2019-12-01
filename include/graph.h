#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct
{
    unsigned int nodesSize;
    int **distances;
} Graph;

Graph *initGraph(char* fileName);

#endif
