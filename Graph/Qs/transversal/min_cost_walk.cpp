// Minimum Cost Walk in Weighted Graph
// Logic: since in question it is given that that we can visit same path any number of time, hence for any two vertex which is same component will have cost=(AND of all edge in that connected component)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> group;
    unordered_map<int, int> dist;
    int dfs(int i, int g, vector<bool> &vis, vector<vector<pair<int, int>>> &adj)
    {
        if (vis[i])
            return INT_MAX;
        vis[i] = true;
        group[i] = g;
        int z = INT_MAX;
        for (auto &e : adj[i])
        {
            int res = dfs(e.first, g, vis, adj);
            z &= (e.second & res);
        }
        return z;
    }
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        int q = query.size();
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            dist[i] = dfs(i, i, vis, adj);
        }
        vector<int> ans;
        for (auto &e : query)
        {
            if (e[0] == e[1])
                ans.push_back(0);
            else if (group[e[0]] != group[e[1]])
                ans.push_back(-1);
            else
                ans.push_back(dist[group[e[1]]]);
        }
        return ans;
    }
};
