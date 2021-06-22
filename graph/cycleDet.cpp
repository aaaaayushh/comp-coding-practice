#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dst;
};

class Graph
{
public:
    int v, e;
    Edge *edge;
};

Graph *createGraph(int v, int e)
{
    Graph *graph = new Graph();
    graph->v = v;
    graph->e = e;
    graph->edge = new Edge[graph->e * sizeof(Edge)];
    return graph;
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    parent[x] = y;
}

int isCycle(Graph *graph)
{
    int *parent = new int[graph->v * sizeof(int)];

    memset(parent, -1, sizeof(int) * graph->v);

    for (int i = 0; i < graph->e; i++)
    {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dst);
        if (x == y)
            return 1;
        Union(parent, x, y);
    }
}
int main()
{
    /* Let us create the following graph
        0
        | \
        |  \
        1---2 */
    int V = 3, E = 3;
    Graph *graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dst = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dst = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dst = 2;

    if (isCycle(graph))
        cout << "graph contains cycle";
    else
        cout << "graph doesn't contain cycle";

    return 0;
}