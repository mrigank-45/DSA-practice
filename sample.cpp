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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        if (isCyclic(numCourses, adj))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
