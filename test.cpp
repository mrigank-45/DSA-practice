#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node,  map<int, vector<int>> adj, unordered_map<int, bool> &visited)
    {
        visited[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        map<int, vector<int>> adj;
        int n = isConnected[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cnt++;
                dfs(i, adj, visited);
            }
        }
    }
};
