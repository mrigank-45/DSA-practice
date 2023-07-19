#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detectBFS(int src, unordered_map<int, list<int>> adj, unordered_map<int, bool> vis, unordered_map<int, int> parent)
    {

        queue<int> q;
        q.push(src);
        vis[src] = 1;
        parent[src] = -1;
        // traverse until queue is not empty
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // go to all adjacent nodes
            for (auto adjacentNode : adj[node])
            {
                // if adjacent node is unvisited
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push(adjacentNode);
                    parent[adjacentNode] = node;
                }
                // if adjacent node is visited and is not it's own parent node
                else if (vis[adjacentNode] && parent[src] != adjacentNode)
                {
                    // yes it is a cycle
                    return true;
                }
            }
        }
        // there's no cycle
        return false;
    }
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
    // Function to detect cycle in an undirected graph using BFS or DFS
    bool isCycle(int V, unordered_map<int, list<int>> adj)
    {
        // using BFS
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectBFS(i, adj, vis, parent))
                {
                    return true;
                }
            }
        }
        return false;

        // using DFS
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
