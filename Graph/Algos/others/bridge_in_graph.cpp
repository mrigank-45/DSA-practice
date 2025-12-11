// A bridge is a edge, if removed, makes the graph disconnected
// ALGO: uses DFS, maintain a disc array and low array, maintain a timer, iterate over all neighbours, update the low if there is a back edge and also update while coming back
// from dfs, then check for the bridge condition, if true, add to the ans. Also maintain parent array so we do not again go to parent node.

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<vector<int>> &allBridges, vector<bool> &visited, vector<int> &disc, vector<int> &low, int parent, int currentVertex, int &time)
{

    visited[currentVertex] = true;

    // Initialize discovery time and low value
    low[currentVertex] = disc[currentVertex] = time;
    time++;

    // Iterate all the adjacent vertices to currentVertex node.
    for (auto neighbour : graph[currentVertex])
    {

        // If child is not visited yet then recur for it.
        if (!visited[neighbour])
        {
            dfs(graph, allBridges, visited, disc, low, currentVertex, neighbour, time);

            // update low of currentVertex while coming back from dfs as it's neighbour may have upadted low
            low[currentVertex] = min(low[neighbour], low[currentVertex]);

            // bridge check
            if (low[neighbour] > disc[currentVertex])
            {
                // Add an edge(currentVertex-neighbour) to answer.
                vector<int> edge(2);
                edge[0] = currentVertex;
                edge[1] = neighbour;
                allBridges.push_back(edge);
            }
        }
        else if (visited[neighbour] && neighbour != parent)
        {
            // this is a back edge, update the low of currentVertex.
            low[currentVertex] = min(low[currentVertex], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> graph(v);

    for (int ei = 0; ei < e; ei++)
    {
        int a = edges[ei][0];
        int b = edges[ei][1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int time = 0;
    vector<bool> visited(v);

    // It stores discovery time of every vertex
    vector<int> disc(v);

    // For every vertex it stores, the discovery time of the earliest discovered
    // vertex to which or any of the vertices in the subtree rooted at is
    // having a back edge.
    vector<int> low(v);

    vector<vector<int>> allBridges; // ans

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(graph, allBridges, visited, disc, low, -1, i, time);
        }
    }

    return allBridges;
}
