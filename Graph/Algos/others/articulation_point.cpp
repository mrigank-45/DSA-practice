// Articulation point is the point, if removed, disconnects the graph into 2 or more compponents. (same algo as of bridge Q, just condition change for articulation point)

// ALGO: uses DFS, maintain a disc array and low array, maintain a timer, iterate over all neighbours, update the low if there is a back edge and also update while coming back
// from dfs, then check for the Articulation condition, if true, add to the ans. Also maintain parent array so we do not again go to parent node. 

// Here, we also have to count child in every call to handle the case of root node.

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, int &time, int u, int parent, vector<bool> &AP)
{
    // To count the children in the DFS Tree.
    int child = 0;
    visited[u] = true;

    // Initialise the discovery time and the low value for u.
    disc[u] = low[u] = time;
    time++;

    for (auto v : adj[u])
    {

        // If v is not visited yet, make it a child of u in the DFS tree and repeat for it.
        if (!visited[v])
        {
            child++;
            dfs(adj, visited, disc, low, time, v, u, AP);

               // update low of currentVertex while coming back from dfs as it's neighbour may have upadted low
            low[u] = min(low[u], low[v]);

            // condition for checking articulation point
            if (low[v] >= disc[u] && parent != -1)
            {
                AP[u] = true;
            }
        }
        else if (visited[v] && v != parent)
        {
             // this is a back edge, update the low of current node.
            low[u] = min(low[u], disc[v]);
        }
    }

    // Case 1, if u is the root of the DFS tree and has more than one child.
    if (parent == -1 && child > 1)
        AP[u] = true;
}

void AP(vector<vector<int>> &adj, int V)
{
    vector<int> disc(V);

    vector<int> low(V);

    vector<bool> visited(V, false);

    vector<bool> AP(V, false);
    int time = 0;
    int par = -1;

    // Using the for loop so that the code works for disconnected the graph.
    for (int u = 0; u < V; ++u)
    {
        if (!visited[u])
        {
            dfs(adj, visited, disc, low, time, u, par, AP);
        }
    }

    // Printing the Articulation points.
    for (int i = 0; i < V; i++)
    {
        if (AP[i] == true)
            cout << i << " ";
    }
}
