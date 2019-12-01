#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graph.h"

#define MAX_DISTANCE INT_MAX

Graph *initGraph(unsigned int nodesSize, unsigned int linksSize, Link *links)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->nodesSize = nodesSize;
    graph->linksSize = linksSize;
    graph->nodes = malloc(sizeof(Node) * nodesSize);
    graph->links = malloc(sizeof(Link) * linksSize);

    for (int i = 0; i < nodesSize; i++)
    {
        graph->nodes[i].name = i;
        graph->nodes[i].visited = false;
        graph->nodes[i].distance = MAX_DISTANCE;
    }
    for (int i = 0; i < linksSize; i++)
    {
        graph->links[i].from = links[i].from;
        graph->links[i].to = links[i].to;
        graph->links[i].weight = links[i].weight;
    }
    return graph;
}

Node *findNode(Graph *graph, NodeName name)
{
    for (int i = 0; i < graph->nodesSize; i++)
    {
        if (graph->nodes[i].name == name)
        {
            return &(graph->nodes[i]);
        }
    }
    return NULL;
}
