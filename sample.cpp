#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> edges, int n, int m, int s, int t)
    {
        vector<int> ADJ[n + 1];
        for (int i = 0; i < m; i++)
        {
            int X, Y;
            X = edges[i][0];
            Y = edges[i][1];
            ADJ[X].push_back(Y);
            ADJ[Y].push_back(X);
        }

        vector<int> visited(n + 1, -1);
        vector<int> parent(n + 1, -1);
        visited[s] = 1;
        queue<int> Q;
        Q.push(s);

        while (Q.size() > 0)
        {
            int currentNode = Q.front();
            Q.pop();

            for (int neighbour : ADJ[currentNode])
            {
                if (visited[neighbour] == -1)
                {
                    visited[neighbour] = 1;
                    Q.push(neighbour);
                    parent[neighbour] = currentNode;
                }
            }
        }

        vector<int> path;
        int currentNode = t;
        path.push_back(t);

        while (currentNode != s)
        {
            currentNode = parent[currentNode];
            path.push_back(currentNode);
        }
        reverse(path.begin(), path.end());

        return path;
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = amount.size();
        vector<int> path = shortestPath(edges, n, n - 1, bob, 0);
        path.push_back(-1);

        unordered_map<int, vector<int>> adj;
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<pair<int, int>> q;
        q.push({0, amount[0]});
        int ans = amount[0], j = 0;
        unordered_set<int> vis;
        vis.insert(0);

        unordered_set<int> visBob;
        visBob.insert(path[0]);

        while (!q.empty())
        {
            int size = q.size();

            if (path[j] != -1)
            {
                j++;
                visBob.insert(path[j]);
            };

            while (size--)
            {
                auto it = q.front();
                q.pop();
                int node = it.first;
                int cost = it.second;
                if (adj[node].size() == 1 && node != 0)
                {
                    ans = max(ans, cost);
                    cout << "node: " << node << " cost: " << cost << endl;
                    continue;
                }

                for (auto child : adj[node])
                {
                    if (child == 0 || vis.find(child) != vis.end())
                        continue;
                    if (child == path[j])
                    {
                        q.push({child, cost + amount[child] / 2});
                        vis.insert(child);
                    }
                    else if (visBob.find(child) != visBob.end())
                    {
                        q.push({child, cost});
                        vis.insert(child);
                    }
                    else
                    {
                        q.push({child, cost + amount[child]});
                        vis.insert(child);
                    }
                }
            }
        }

        return ans;
    }
};
