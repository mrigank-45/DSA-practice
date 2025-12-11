// ALGO: Maintain a pathVis array, mark true when you enter it's DFS, false when leave, if adjacent node is visited as well as pathVis, then there is a cycle.
// Can also detect cycle in directed graphs using topo sort (kahn's algo).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfsCheck(int node, unordered_map<int, vector<int>> &adj,  unordered_map<int,bool> &vis, unordered_map<int,bool> &pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfsCheck(it, adj, vis, pathVis) == true)
                    return true;
            }
            else if (vis[it] && pathVis[it])
            {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
    
    // Function to detect cycle in a directed graph by DFS
    bool isCyclic(int V, unordered_map<int, vector<int>> &adj)
    {
        unordered_map<int,bool> vis;
        unordered_map<int,bool> pathVis;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, adj, vis, pathVis) == true)
                    return true;
            }
        }
        return false;
    }
};
