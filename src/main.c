#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "tspBranchAndBound.h"
#include "tspBruteForce.h"

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
    printf("Path: ");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d -> ", path[i] + 1);
    }
    printf("%d\n", path[size - 1] + 1);
}

void printPathLength(Graph *graph, int *path)
{
    int length = 0;
    for (int i = 1; i <= graph->size; i++)
    {
        length += graph->distances[path[i - 1]][path[i]];
    }
    printf("Length: %d\n", length);
}

int main(int argc, char **argv)
{
    char *fileName = getFileName(argc, argv);
    Graph *graph = initGraph(fileName);

    int *pathBB = branchAndBound(copyGraph(graph));
    printPath(pathBB, graph->size + 1);
    printPathLength(graph, pathBB);

    int *pathBF = bruteForce(copyGraph(graph));
    printPath(pathBF, graph->size + 1);
    printPathLength(graph, pathBF);

    free(pathBB);
    free(pathBF);
    free(graph);
}
