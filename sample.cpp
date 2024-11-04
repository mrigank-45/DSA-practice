#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < rooms[i].size(); j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<bool> visited(n, false);
        dfs(0, adj, visited);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;
    }
};
