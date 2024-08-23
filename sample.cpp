#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(map<long long, vector<pair<long long, long long>>> &adjList, long long vertices, long long source)
    {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        vector<long long> distance(vertices, LLONG_MAX);

        pq.push({0, source});

        distance[source] = 0;
        vector<bool> visited(vertices, false);

        while (!pq.empty())
        {
            long long u = pq.top().second;

            pq.pop();

            visited[u] = true;

            for (auto it : adjList[u])
            {
                long long v = it.first;
                long long dist = it.second;

                if (visited[v] == false && distance[v] > distance[u] + dist)
                {
                    distance[v] = distance[u] + dist;

                    pq.push({distance[v], v});
                }
            }
        }

        return distance;
    }
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        map<long long, vector<pair<long long, long long>>> mp;
        for (long long i = 0; i < original.size(); i++)
        {
            long long u = original[i] - 'a';
            long long v = changed[i] - 'a';
            long long val = cost[i];
            mp[u].push_back({v, val});
        }

        map<long long, vector<long long>> dist;
        for (long long i = 0; i < 26; i++)
        {
            dist[i] = solve(mp, 26, i);
        }
        long long ans = 0;

        for (long long i = 0; i < source.size(); i++)
        {
            if (source[i] != target[i])
            {
                if (dist[source[i] - 'a'][target[i] - 'a'] != LLONG_MAX)
                {
                    ans += dist[source[i] - 'a'][target[i] - 'a'];
                }
                else
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
