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
            if (matrix[i][j] != INT_MAX)
            {
                matrix[i][j] -= min;
            }
        }
    }
}

int *branchAndBoundInternal(Graph *graph, int *segments, int segmentsNum)
{
    if (segmentsNum >= graph->size * 2)
    {
        return segments;
    }

    // reduce rows
    reduce(graph->distances, graph->size);

    // reduce columns
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
                if ((sum > maxScore) || (rowMin == INT_MAX && colMin == INT_MAX))
                {
                    maxScore = sum;
                    iMax = i;
                    jMax = j;
                }
            }
        }
    }

    for (int i = 0; i < graph->size; i++)
    {
        graph->distances[iMax][i] = INT_MAX;
        graph->distances[i][jMax] = INT_MAX;
    }
    graph->distances[jMax][iMax] = INT_MAX;

    segments[segmentsNum++] = iMax;
    segments[segmentsNum++] = jMax;

    printf("%d ", iMax + 1);
    printf("%d \n", jMax + 1);
    //print(graph);

    return branchAndBoundInternal(graph, segments, segmentsNum);
}

int *glueSegments(int *segments, int segmentsSize)
{
    int pathSize = segmentsSize / 2 + 1;
    int *path = malloc((pathSize) * sizeof(int));

    path[0] = segments[0];
    int desired = path[0];
    int num = 1;
    int i = 0;

    while (num < pathSize)
    {
        if (segments[i] == desired)
        {
            i++;
            path[num] = segments[i];
            desired = path[num];
            num++;
            i++;
        } else
        {
            i += 2;
            if (i >= segmentsSize)
            {
                i = 0;
            }
        }
    }

    return path;
}

int *branchAndBound(Graph *graph)
{
    int *segments = malloc((graph->size * 2) * sizeof(int));
    branchAndBoundInternal(graph, segments, 0);

    int *path = glueSegments(segments, graph->size * 2);

    free(segments);
    return path;
}