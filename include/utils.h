#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include "graph.h"

int **copyMatrix(int **matrix, int size);

void rotateMatrix(int **matrix, int size);

int *copyArray(int *array, int size);

bool isArrayContains(int value, int *array, int arraySize);

int calculatePathLength(Graph *graph, int *path);

#endif
