#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "utils.h"
#include "graph.h"

int **copyMatrix(int **matrix, int size)
{
    int **copyMatrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        copyMatrix[i] = malloc(size * sizeof(int));
        memcpy(copyMatrix[i], matrix[i], size * sizeof(int));
    }
    return copyMatrix;
}

void rotateMatrix(int **matrix, int size)
{
    int tmp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j > i)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
}

int *copyArray(int *array, int size)
{
    int *copyArray = malloc(size * sizeof(int));
    memcpy(copyArray, array, size * sizeof(int));
    return copyArray;
}

bool isArrayContains(int value, int *array, int arraySize)
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
