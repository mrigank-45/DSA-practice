// Finds minimum distance from a src node to all the nodes.
// ALGO: Use a min heap (pair<distance,node>), and somewhat like BFS, till heap is not empty, push neighbours(non-visited) if minimum distance array(ans) can be updated.
// Applicable to DAGs (fails in -ve weighted graphs)
// TC: O((V + E)logV)

#include <bits/stdc++.h>
using namespace std;

vector<int> Solve(vector<vector<pair<int, int>>> &adjList, int vertices, int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

    vector<int> distance(vertices, INT_MAX);

    // Push the source vertex in the priority queue.
    pq.push({0, source});

    // Distance of a vertex to itself is 0.
    distance[source] = 0;
    vector<bool> visited(vertices, false);

    while (!pq.empty())
    {
        int u = pq.top().second;

        pq.pop();

        visited[u] = true;

        // Update the distances of the adjacent nodes.
        for (auto it : adjList[u])
        {
            int v = it.first;
            int dist = it.second;

            if (visited[v] == false && distance[v] > distance[u] + dist)
            {
                distance[v] = distance[u] + dist;

                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pair<int, int>>> adjList(vertices);

    // Create an adjacency list.
    for (int i = 0; i < edge.size(); i++)
    {
        adjList[edge[i][0]].push_back({edge[i][1], edge[i][2]});
        adjList[edge[i][1]].push_back({edge[i][0], edge[i][2]});
    }

    return Solve(adjList, vertices, source);
}
