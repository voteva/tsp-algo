#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "tsp.h"

char *getFileName(int argc, char *argv[])
{
    if (argc < 2)
    {
        perror("No file path specified");
        exit(EXIT_FAILURE);
    }
    return argv[1];
}

void printPath(int *path, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d -> ", path[i] + 1);
    }
    printf("%d\n", path[size - 1] + 1);
}

int main(int argc, char **argv)
{
    char *fileName = getFileName(argc, argv);
    Graph *graph = initGraph(fileName);
    int *path = branchAndBound(graph);

    printPath(path, graph->size + 1);

    free(path);
    free(graph);
}
