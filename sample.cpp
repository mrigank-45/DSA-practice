#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        // Create graph as adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (const auto &edge : edges)
        {
            int u = edge[0], v = edge[1], length = edge[2];
            graph[u].emplace_back(v, length);
            graph[v].emplace_back(u, length);
        }

        // Min-heap for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n, INT_MAX);

        // Start from node 0
        pq.emplace(0, 0); // (time, node)
        dist[0] = 0;

        while (!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time > disappear[node])
                continue; // Skip if node has disappeared

            for (const auto &neighbour : graph[node])
            {
                int nextNode = neighbour.first;
                int edgeLength = neighbour.second;

                if (time + edgeLength <= disappear[nextNode] && time + edgeLength < dist[nextNode])
                {
                    dist[nextNode] = time + edgeLength;
                    pq.emplace(dist[nextNode], nextNode);
                }
            }
        }

        // Convert unreachable nodes distance to -1
        for (int i = 0; i < n; ++i)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};
