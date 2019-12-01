#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

int **copy(int **matrix, int size)
{
    int **copyMatrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        copyMatrix[i] = malloc(size * sizeof(int));
        memcpy(copyMatrix[i], matrix[i], size * sizeof(int));
    }
    return copyMatrix;
}

void rotate(int **matrix, int size)
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
