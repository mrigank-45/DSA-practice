// Shortest path for undirected graphs given source and target.
// ALGO: Make parent mapping by BFS and then just transverse from target to source, and reverse.
// we can do it for weighted as well by using adjacency list which also contains weight along with nodes.

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // We will store graph in an adjecency list.
    vector<int> ADJ[n + 1];
    for (int i = 0; i < m; i++)
    {
        int X, Y;
        X = edges[i].first;
        Y = edges[i].second;
        ADJ[X].push_back(Y);
        ADJ[Y].push_back(X);
    }

    vector<int> visited(n + 1, -1);
    vector<int> parent(n + 1, -1);
    visited[s] = 1;
    queue<int> Q;
    Q.push(s);

    while (Q.size() > 0) // not empty
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

    // Now we will backtrack and recreate the path from S to T using visited array.
    vector<int> path;
    int currentNode = t;

    // We will start from T and try to go back from here until we reaches S.
    path.push_back(t);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        path.push_back(currentNode);
    }
    reverse(path.begin(), path.end());

    return path;
}
