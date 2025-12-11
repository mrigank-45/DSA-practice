// Shortest path for directed acyclic graph assuming source node as 0, adjacency list also contains weight along with nodes.
// ALGO: Find topo sort order stack, then use the stack to updates the final distance array which is our ans.

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[i] = 1;
    for (auto j : adj[i])
    {
        if (vis[j.first] == 0)
        {
            dfs(j.first, adj, vis, st);
        }
    }
    st.push(i);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Creating an adjacency list, which stores {destination, weight}.
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    // Initializing empty stack 'st'.
    stack<int> st;

    // Finding topological sort.
    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, vis, st);
        }
    }

    // Initializing array 'dis' of size 'N' with 10^9.
    vector<int> dis(n, 1e9); // answer
    dis[0] = 0;

    // Finding shortest distances.
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto i : adj[node])
        {
            int neighbour = i.first;
            int weight = i.second;
            if (dis[neighbour] > dis[node] + weight)
            {
                // Updating dis[v].
                dis[neighbour] = dis[node] + weight;
            }
        }
    }

    return dis;
}
