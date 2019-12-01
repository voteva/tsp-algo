#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graph.h"

#define MAX_DISTANCE INT_MAX

Graph *initGraph(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Incorrect file name");
        exit(EXIT_FAILURE);
    }

    int nodesSize = 0;
    fscanf(file, "%d", &(nodesSize));

    Graph *graph = malloc(sizeof(Graph));
    graph->nodesSize = nodesSize;
    graph->distances = malloc(sizeof(int *) * (graph->nodesSize));

    for (int i = 0; i < nodesSize; ++i)
    {
        graph->distances[i] = malloc(sizeof(int) * (nodesSize));
        for (int j = 0; j < nodesSize; ++j)
        {
            if (!fscanf(file, "%d", &(graph->distances[i][j])))
            {
                perror("Incorrect file content");
                return NULL;
            }
        }
    }

    fclose(file);
    return graph;
}