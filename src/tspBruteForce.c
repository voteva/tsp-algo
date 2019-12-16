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

int calculatePathLength(Graph *graph, int *path)
{
    int length = 0;
    for (int i = 1; i <= graph->size; i++)
    {
        length += graph->distances[path[i - 1]][path[i]];
    }
    return length;
}

int *bruteForceInternal(Graph *graph, int currentNode, int *visitedNodes, int visitedNodesSize)
{
    visitedNodes[visitedNodesSize++] = currentNode;

    if (visitedNodesSize == graph->size)
    {
        if (graph->distances[currentNode][visitedNodes[0]] != INT_MAX)
        {
            visitedNodes[visitedNodesSize] = visitedNodes[0];
            return visitedNodes;
        } else
        {
            return NULL;
        }
    }

    int minLength = INT_MAX;
    int *bestPath = NULL;
    for (int i = 0; i < graph->size; i++)
    {
        if (contains(i, visitedNodes, visitedNodesSize)) continue;
        if (graph->distances[currentNode][i] == INT_MAX) continue;

        int *path = bruteForceInternal(graph, i, copyArray(visitedNodes, graph->size + 1), visitedNodesSize);
        if (path != NULL)
        {
            int length = calculatePathLength(graph, path);
            if (length < minLength)
            {
                minLength = length;
                bestPath = copyArray(path, graph->size + 1);
            }
        }
        free(path);
    }

    return bestPath;
}

int *bruteForce(Graph *graph)
{
    printf("Running Brute-Force solver...\n");

    int *visitedNodes = malloc((graph->size + 1) * sizeof(int));
    int *result = bruteForceInternal(graph, 0, visitedNodes, 0);

    free(graph);
    free(visitedNodes);

    return result;
}