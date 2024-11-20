#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(unordered_map<int, vector<int>> &adj, int n, int i, vector<int> &vis)
    {
        queue<int> q;
        q.push(i);
        int color = -1;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                int ele = q.front();
                q.pop();

                vis[ele] = color;

                for (auto it : adj[ele])
                {
                    if (vis[it] < 0 && vis[ele] == vis[it])
                    {
                        return false;
                    }
                    else if (vis[it] == 0)
                    {
                        q.push(it);
                    }
                }
            }
            if (color == -1)
            {
                color = -2;
            }
            else
            {
                color = -1;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        // build the adj list
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                adj[i].push_back(it);
            }
        }

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                if (!solve(adj, n, i, vis))
                {
                    return false;
                }
            }
        }

        return true;
    }
};
