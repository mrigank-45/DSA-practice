#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(map<int, vector<pair<int, int>>> &adj, int node, int k, int parent, int val)
    {
        int ans = 0;
        for (auto edge : adj[node])
        {
            if (edge.first == parent)
                continue;
            if ((val + edge.second) % k == 0)
            {
                ans += 1 + helper(adj, edge.first, k, node, val + edge.second);
            }
            else
            {
                ans += helper(adj, edge.first, k, node, val + edge.second);
            }
        }
        return ans;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
        int n = edges.size() + 1;
        int k = signalSpeed;
        map<int, vector<pair<int, int>>> adj;

        for (auto edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        map<int, vector<int>> valid;
        for (int i = 0; i < n; i++)
        {
            for (auto edge : adj[i])
            {
                if (edge.second % k == 0)
                {
                    valid[i].push_back(1 + helper(adj, edge.first, k, i, edge.second));
                }
                else
                {
                    valid[i].push_back(helper(adj, edge.first, k, i, edge.second));
                }
            }
        }

        vector<int> ans(n, 0);

        for (auto it : valid)
        {
            int temp = 0;
            vector<int> v = it.second;
            if (v.size() == 0)
            {
                ans[it.first] = 0;
                continue;
            }
            for (int i = 0; i < v.size(); i++)
            {

                if (v[i] == 0)
                    continue;
                for (int j = i + 1; j < v.size(); j++)
                {

                    if (v[j] == 0)
                        continue;

                    temp += v[i] * v[j];
                }
            }
            ans[it.first] = temp;
        }

        return ans;
    }
};
