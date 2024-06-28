// Used to find minimum spanning tree (applicable to undirected graphs with weights)
// we need a Disjoint Set data structure whether 2 nodes are in the same component or not in constant time. (func: findParent,unionByRank)

// ALGO: Sort the edges by weight, transverse them and if they are not in same component, add weight to ans and join them using disjoint set.

//  Time Complexity = O(E*log(E))
//  Space Complexity = O(V + E)

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        // initialize the parent and rank array
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int node)
    {
        // base case: it means it's last node
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]); // For Path Compression
        // return findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        if (parent_u == parent_v)
        {
            return;
        }

        if (rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_v] < rank[parent_u])
        {
            parent[parent_v] = parent_u;
        }
        else
        {
            parent[parent_v] = parent_u;
            rank[parent_u]++; // update the rank
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // preparing linear structure to sort them by weight and transverse them
        vector<pair<int, pair<int, int>>> edges;   // {wt,{node1,node2}
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}}); 
            }
        }
        sort(edges.begin(), edges.end());

        // initialy we assume all nodes are disconnected
        DisjointSet ds(V);
        int mstWt = 0;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findParent(u) != ds.findParent(v)) // if not in same component, union them
            {
                mstWt += wt; // add the weight to MST
                ds.unionByRank(u, v);
            }
        }

        return mstWt;
    }
};
