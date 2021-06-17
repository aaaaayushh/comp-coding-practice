#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isBipartite(vector<int> adj[], int v, vector<bool> &visited, vector<int> &color)
{
    for (int u : adj[v])
    {
        if (visited[u] == false)
        {
            visited[u] = true;
            color[u] = !color[v];
            if (!isBipartite(adj, u, visited, color))
                return false;
        }
        else if (color[u] == color[v])
            return false;
    }
    return true;
}

int main()
{
    int n = 6;
    vector<int> adj[n + 1];
    vector<bool> visited(n + 1);
    vector<int> color(n + 1);

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 1);
    visited[1] = true;
    for (int i = 1; i <= 6; i++)
    {
        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
            cout << *j << ' ';
        cout << '\n';
    }
    color[1] = 0;
    if (isBipartite(adj, 1, visited, color))
    {
        cout << "Graph is Bipartite\n";
    }
    else
    {
        cout << "Graph is not Bipartite\n";
    }

    return 0;
}