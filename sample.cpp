#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;
    int solve(int node, int prev, unordered_map<int, vector<int>> &adj)
    {
        int size = 0;
        int singleSize = -1;
        bool good = true;
        for (auto neighbour : adj[node])
        {
            if (neighbour == prev)
            {
                continue; 
            }
            int temp = solve(neighbour, node, adj);

            size += temp;
            if (singleSize == -1)
            {
                singleSize = temp;
            }
            else if(singleSize != temp)
            {
                good = false;
            }
        }
        if (good)
        {
            ans++;
        }
        return size + 1;
    }
    int countGoodNodes(vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int temp = solve(0, -1, adj);
        return ans;
    }
};
