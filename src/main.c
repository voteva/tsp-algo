#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "utils.h"
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

void printPath(Graph *graph, int *path)
{
    printf("Path: ");
    for (int i = 0; i < graph->size; i++)
    {
        printf("%d -> ", path[i] + 1);
    }
    printf("%d\n", path[graph->size] + 1);
}

void printPathLength(Graph *graph, int *path)
{
    int length = calculatePathLength(graph, path);
    printf("Length: %d\n", length);
}

int main(int argc, char **argv)
{
    char *fileName = getFileName(argc, argv);
    Graph *graph = initGraph(fileName);

    int *pathBB = branchAndBound(copyGraph(graph));
    printPath(graph, pathBB);
    printPathLength(graph, pathBB);

    int *pathBF = bruteForce(copyGraph(graph));
    printPath(graph, pathBF);
    printPathLength(graph, pathBF);

    free(pathBB);
    free(pathBF);
    free(graph);
}
