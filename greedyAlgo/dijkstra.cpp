#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#define v 9
using namespace std;
//function to find the vertex with the minimum distance value, the set of vertices not yet included in shortest path tree
int minDist(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
        if (sptSet[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}

void printSol(int dist[])
{
    cout << "Vertex\t\tDistance from source\n";
    for (int i = 0; i < v; i++)
        cout << i << "\t\t" << dist[i] << "\n";
}

void dijkstra(int graph[v][v], int src)
{
    int dist[v]; //output array. dist[i] holds the shortest distance from src to i

    bool sptSet[v]; //sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    //distance of source vertex from itself is always 0
    dist[src] = 0;

    //find shortest path for all vertices
    for (int count = 0; count < v - 1; count++)
    {
        //pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.

        int u = minDist(dist, sptSet);
        cout << "u:" << u << '\n';
        //mark the picked vertex as true
        sptSet[u] = true;

        //update dist value of adjacent vertices of the picked vertex
        for (int i = 0; i < v; i++)
        {
            //update dist[i] only if not in sptSet,there is an edge from u to i, and total weight of path from src to i through u is smaller
            //than current value of dist[i]
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
        }

        printSol(dist);
    }
}

int main()
{
    /* Let us create the example graph discussed above */
    int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}