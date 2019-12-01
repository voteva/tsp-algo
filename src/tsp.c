#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graph.h"
#include "matrix.h"

int getMin(int *values, int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (values[i] < min)
        {
            min = values[i];
        }
    }
    return min;
}

void reduce(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = getMin(matrix[i], size);
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] -= min;
        }
    }
}

void branchAndBound(Graph *graph)
{
    reduce(graph->distances, graph->size);
    rotate(graph->distances, graph->size);

    reduce(graph->distances, graph->size);
    rotate(graph->distances, graph->size);

    int iMax = 0;
    int jMax = 0;
    int maxScore = -1;
    for (int i = 0; i < graph->size; i++)
    {
        for (int j = 0; j < graph->size; j++)
        {
            if (graph->distances[i][j] == 0)
            {
                graph->distances[i][j] = INT_MAX;
                int rowMin = getMin(graph->distances[i], graph->size);
                rotate(graph->distances, graph->size);

                int colMin = getMin(graph->distances[i], graph->size);
                rotate(graph->distances, graph->size);

                graph->distances[i][j] = 0;
                int sum = rowMin + colMin;
                if (sum > maxScore)
                {
                    maxScore = sum;
                    iMax = i;
                    jMax = j;
                }
            }
        }
    }
    graph->distances[iMax][jMax] = INT_MAX;
    graph->distances[jMax][iMax] = INT_MAX;

    printf("%d ", iMax);
    printf("%d \n", jMax);
    print(graph);
}
