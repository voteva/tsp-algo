#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

float getTimeDifferenceSec(struct timeval t0, struct timeval t1)
{
    return (double) (t1.tv_usec - t0.tv_usec) / 1000000 + (double) (t1.tv_sec - t0.tv_sec);
}

int main(int argc, char **argv)
{
    char *fileName = getFileName(argc, argv);
    Graph *graph = initGraph(fileName);

    struct timeval timeStart, timeFinish;

    gettimeofday(&timeStart, 0);

    int *pathBF = bruteForce(copyGraph(graph));
    printPath(graph, pathBF);
    printPathLength(graph, pathBF);

    gettimeofday(&timeFinish, 0);

    float elapsed = getTimeDifferenceSec(timeStart, timeFinish);

    printf("Time: %.3f\n", elapsed);

    free(pathBF);
    free(graph);
}
