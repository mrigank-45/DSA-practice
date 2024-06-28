// Finds minimum distance from a src node to all the nodes, applicable to DAGs with -ve weights (but no -ve cycle)
// ALGO: maintain a distance array, apply (d[u] + w) < d[v]) to all edges n-1 times, we get our ans.    
// TC: O(V*E)

#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Create a vector to store the distances from source.
    vector<int> distance(n + 1, INT_MAX);
    // Distance of source to source is 0.
    distance[src] = 0;

    // Apply bellmanford algorithm.
    for (int i = 1; i < n; i++)  // (n-1) times
    {
        for (int j = 0; j < m; j++)  // m is no. of edges
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if ((distance[u] + w) < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Return the distance of destination.
    return distance[dest];
}
