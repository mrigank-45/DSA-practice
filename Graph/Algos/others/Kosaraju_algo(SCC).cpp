// Find the number of strongly connected components in the graph. A component is called a Strongly Connected Component(SCC) only if for every possible pair of vertices
// (u, v) inside that component, u is reachable from v and v is reachable from u.

// ALGO: Step 1: find topo sort, Step 2: transpose the edges, Step 3: do dfs till stack is not empty, increment count after dfs of every component, that is our ans.

#include <bits/stdc++.h>
using namespace std;

#include <stack>

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited)
{

    visited[u] = true;

    // Traverse the adjacent nodes.
    int edges = graph[u].size();
    for (int i = 0; i < edges; i++)
    {
        int v = graph[u][i];
        if (visited[v] != true)
        {
            dfs(v, graph, visited);
        }
    }
    return;
}

vector<vector<int>> getTranspose(int vertices, vector<vector<int>> &graph)
{
    vector<vector<int>> transposeGraph(vertices);

    //  Generate the transpose of the given graph by reversing the direction of every edge.
    for (int i = 0; i < vertices; i++)
    {
        int edges = graph[i].size();

        for (int j = 0; j < edges; j++)
        {
            int u = graph[i][j];

            transposeGraph[u].push_back(i);
        }
    }

    return transposeGraph;
}

void topoSort(int u, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &stack)
{

    visited[u] = true;

    // Traverse the adjacent nodes.
    int edges = graph[u].size();
    for (int i = 0; i < edges; i++)
    {
        int v = graph[u][i];
        if (visited[v] != true)

        {
            topoSort(v, graph, visited, stack);
        }
    }
    stack.push(u);

    return;
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(v);

    int e = edges.size();
    for (int i = 0; i < e; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        graph[a].push_back(b);
    }

    stack<int> stack;
    vector<bool> visited(v, false);

    // Apply DFS to find topo sort in stack
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            topoSort(i, graph, visited, stack);
        }
    }

    // Get the tranpose of the given graph.
    vector<vector<int>> transposeGraph = getTranspose(v, graph);

    // Mark all the vertices as unvisited.
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    // Create a variable to store the number of connected components in the graph.
    int count = 0;

    // Visit all the SCCs one by one.
    while (!stack.empty())
    {
        int node = stack.top();
        stack.pop();

        if (visited[node] == false)
        {
            dfs(node, transposeGraph, visited);

            // Traversed a SCC. So, increment the count by one.
            count++;
        }
    }

    return count;
}
