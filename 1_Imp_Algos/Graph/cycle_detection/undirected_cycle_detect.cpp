// ALGO: Maintain a parent array during DFS, if adjacent node is visited and is not it's own parent node, then there is a cycle.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detectDFS(int node, int parent, unordered_map<int, bool> vis, unordered_map<int, list<int>> adj)
    {
        vis[node] = 1;

        // visit adjacent nodes
        for (auto adjacentNode : adj[node])
        {
            // unvisited adjacent node
            if (!vis[adjacentNode])
            {
                bool cyclePresent = detectDFS(adjacentNode, node, vis, adj);
                if (cyclePresent)
                {
                    return true;
                }
            }
            // visited node but not a parent node
            else if (vis[adjacentNode] && adjacentNode != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph using DFS
    bool isCycle(int V, unordered_map<int, list<int>> adj)
    {
        unordered_map<int, bool> vis;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectDFS(i, -1, vis, adj) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
