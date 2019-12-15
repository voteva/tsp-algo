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

    int size = 0;
    fscanf(file, "%d", &(size));

    Graph *graph = malloc(sizeof(Graph));
    graph->size = size;
    graph->distances = malloc(sizeof(int *) * (graph->size));

    for (int i = 0; i < size; ++i)
    {
        graph->distances[i] = malloc(sizeof(int) * (size));
        for (int j = 0; j < size; ++j)
        {
            if (!fscanf(file, "%d", &(graph->distances[i][j])))
            {
                perror("Incorrect file content");
                return NULL;
            }
        }
        graph->distances[i][i] = MAX_DISTANCE;
    }

    fclose(file);
    return graph;
}

Graph *copyGraph(Graph *graph)
{
    Graph *graphCopy = malloc(sizeof(Graph));
    graphCopy->distances = malloc(sizeof(int *) * (graph->size));
    graphCopy->size = graph->size;

    for (int i = 0; i < graph->size; ++i)
    {
        graphCopy->distances[i] = malloc(sizeof(int) * (graph->size));
        for (int j = 0; j < graph->size; ++j)
        {
            graphCopy->distances[i][j] = graph->distances[i][j];
        }
    }
    return graphCopy;
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->size; i++)
    {
        for (int j = 0; j < graph->size; j++)
        {
            printf("%d ", graph->distances[i][j]);
        }
        printf("\n");
    }
}
