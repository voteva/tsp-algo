#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

char *getFilePath(int argc, char *argv[])
{
    if (argc < 2)
    {
        perror("No file path specified");
        exit(EXIT_FAILURE);
    }
    return argv[1];
}

Graph *readGraph(char *filePath)
{
    FILE *file = fopen(filePath, "r");
    if (file == NULL)
    {
        perror("Incorrect file");
        exit(EXIT_FAILURE);
    }

    int nodesSize = 0;
    fscanf(file, "%d", &nodesSize);

    int linksSize = 0;
    fscanf(file, "%d", &linksSize);

    Link *links = malloc(sizeof(*links) * linksSize);
    for (int i = 0; i < linksSize; i++)
    {
        fscanf(file, "%d", &links[i].from);
        fscanf(file, "%d", &links[i].to);
        fscanf(file, "%d", &links[i].weight);
    }

    fclose(file);
    return initGraph(nodesSize, 0, links);
}

int main(int argc, char **argv)
{
    char *filePath = getFilePath(argc, argv);
    Graph *graph = readGraph(filePath);

    for (int i = 0; i < graph->nodesSize; i++)
    {
        printf("%d\n", graph->nodes[i].name);
    }
}
