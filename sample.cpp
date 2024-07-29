#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> magicTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<long long, long long>>> adj(n);
        vector<long long> answer(n, LLONG_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        // Build the adjacency list
        for (const auto &edge : edges)
        {
            long long u = edge[0];
            long long v = edge[1];
            long long t = edge[2];
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }

        // Add all magical nodes (nodes with degree 1) to the priority queue
        for (long long i = 0; i < n; ++i)
        {
            if (adj[i].size() == 1)
            {
                pq.push({0, i});
                answer[i] = 0;
            }
        }

        // Dijkstra's algorithm
        while (!pq.empty())
        {
            long long current_time = pq.top().first;
            long long node = pq.top().second;

            pq.pop();

            if (current_time > answer[node])
                continue;

            for (const auto &neighbor : adj[node])
            {
                long long next_node = neighbor.first;
                long long travel_time = neighbor.second;

                if (current_time + travel_time < answer[next_node])
                {
                    answer[next_node] = current_time + travel_time;
                    pq.push({answer[next_node], next_node});
                }
            }
        }

        return answer;
    }
};
