#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define NodeName int

typedef struct
{
    NodeName from;
    NodeName to;
    int weight;
} Link;

typedef struct
{
    NodeName name;
    bool visited;
    int distance;
} Node;

typedef struct
{
    unsigned int nodesSize;
    unsigned int linksSize;
    Node *nodes;
    Link *links;
} Graph;

Graph *initGraph(unsigned int nodesSize, unsigned int linksSize, Link *links);

Node *findNode(Graph *graph, NodeName name);

#endif
