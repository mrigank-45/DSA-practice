// Create a graph using Adjacency list and print them. n-> nodes, m->edges.
#include <bits/stdc++.h>
using namespace std;

void createAndPrintAdjacency(int n, int m, vector<vector<int>> &edges)
{
    map<int, vector<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (auto it : adjList)
    {
        cout << it.first << "-> ";
        for (int i = 0; i < it.second.size(); i++)
        {
            cout << it.second[i] << " ";
        }
        cout << endl;
    }
}
