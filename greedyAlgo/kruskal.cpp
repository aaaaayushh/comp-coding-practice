#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src, dst, weight;
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
    graph->edge = new Edge[e];
    return graph;
}
class subset
{
public:
    int parent;
    int rank;
};

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].parent)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].parent)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

//compare two edges according to their weights.
//used in qsort() for sorting an array of edges
int myComp(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->weight > b1->weight;
}

void kruskal(Graph *graph)
{
    int v = graph->v;
    Edge result[v]; //stores the resultant mst
    int e = 0;
    int i = 0;

    //step1:sort edge in increasing order of their weight.
    qsort(graph->edge, graph->e, sizeof(graph->edge[0]), myComp);

    //allocate memory for creating v subsets
    subset *subsets = new subset[(v * sizeof(subset))];

    //create v subsets with single elements
    for (int i = 0; i < v; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    //no of edges to be taken is equal to v-1
    while (e < v - 1 && i < graph->e)
    {
        //step 2:pick the smallest edge. increment the index for next iteration
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dst);

        //if including this edge doesn't cause a cycle, include it in the result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        //else discard the next edge
    }
    cout << "Following are the edges in the constructed MST\n";
    int minCost = 0;
    for (i = 0; i < e; i++)
    {
        cout << result[i].src << " -- " << result[i].dst << " == " << result[i].weight << endl;
        minCost = minCost + result[i].weight;
    }
    cout << "Min cost spanning tree:" << minCost << endl;
}

int main()
{
    /* Let us create following weighted graph
            10
        0--------1
        | \ |
    6| 5\ |15
        | \ |
        2--------3
            4 */
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph *graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dst = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dst = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dst = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dst = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dst = 3;
    graph->edge[4].weight = 4;

    // Function call
    kruskal(graph);

    return 0;
}
//time complexity: O(ElogE) or O(ElogV)