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
            return node;
        return parent[node] = findParent(parent[node]); // For Path Compression
        // return findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; // update the rank
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < n; i++)
        {

            int u= connections[i][0];
            int v = connections[i][1];
            int wt = 1;

            edges.push_back({wt, {u, v}});
            edges.push_back({wt, {v, u}});
        }
        sort(edges.begin(), edges.end());

        // initialy we assume all nodes are disconnected
        DisjointSet ds(n);
        int mstWt = 0;
        int cnt = 0;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findParent(u) != ds.findParent(v)) 
            {
                mstWt += wt; 
                cnt++;
                ds.unionByRank(u, v);
            }
        }

        return cnt;
    }
};
