#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int n, vector<vector<int>> &edges, int source, int destination, unordered_map<int, vector<int>> &adj, unordered_set<int> &s)
    {
        if (source == destination)
        {
            return true;
        }

        s.insert(source);
        for (auto it : adj[source])
        {
            if (s.find(it) == s.end())
            {
                if (solve(n, edges, it, destination, adj, s))
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int> s;

        return solve(n, edges, source, destination, adj, s);
    }
};
