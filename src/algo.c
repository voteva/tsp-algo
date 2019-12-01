#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main(int argc, char **argv)
{
    int nodesSize = 10;
    Link *links = NULL;
    Graph *graph = initGraph(nodesSize, 0, links);
    for (int i = 0; i < nodesSize; i++)
    {
        printf("%d\n", graph->nodes[i].name);
    }

    Node *node = findNode(graph, 4);
    printf("%d\n", node->distance);
}
