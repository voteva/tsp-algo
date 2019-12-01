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

int main(int argc, char **argv)
{
    char *fileName = getFileName(argc, argv);
    Graph *graph = initGraph(fileName);
    branchAndBound(graph);
}
