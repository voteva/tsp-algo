#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#include "tspBruteForce.h"
#include "graph.h"

int *copyArray(int *array, int size)
{
    int *copyArray = malloc(size * sizeof(int));
    memcpy(copyArray, array, size * sizeof(int));
    return copyArray;
}

bool contains(int value, int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (value == array[i])
        {
            return true;
        }
    }
    return false;
}

int *bruteForceInternal(Graph *graph, int currentNode, int *visitedNodes, int visitedNodesSize)
{
    visitedNodes[visitedNodesSize++] = currentNode;

    printf("node %d\n", currentNode);
    printf("node size %d\n", visitedNodesSize);

    for (int i = 0; i < graph->size; i++)
    {
        if (contains(i, visitedNodes, visitedNodesSize)) continue;
        if (graph->distances[currentNode][i] == INT_MAX) continue;
        return bruteForceInternal(graph, i, copyArray(visitedNodes, graph->size), visitedNodesSize);
    }

    if (graph->distances[currentNode][visitedNodes[0]] == INT_MAX)
    {
        return NULL;
    }

    visitedNodes[visitedNodesSize++] = visitedNodes[0];
    return visitedNodes;
}

int *bruteForce(Graph *graph)
{
    int *visitedNodes = malloc((graph->size + 1) * sizeof(int));
    int *result = bruteForceInternal(graph, 0, visitedNodes, 0);

    free(graph);
    return result;
}