#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#include "tspBruteForce.h"
#include "graph.h"
#include "utils.h"

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
        if (isArrayContains(i, visitedNodes, visitedNodesSize)) continue;
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