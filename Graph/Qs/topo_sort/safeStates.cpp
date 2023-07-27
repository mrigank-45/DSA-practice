// Eventual Safe States: Given a graph, Return an array containing all the safe nodes (every possible path starting from that node leads to a terminal node) of the graph.
// ALGO: Use topo sort, for that, first reverse the edges and then impliment normal topo sort ans get the ans. Why this works because, all possible paths starting from a node 
// are going to end at some terminal node unless there exists a cycle, so in topo sort, after reversing the edges, we start from terminal nodes and keep ading the nodes, but 
// when cycle comes, we do not add node, hence get only the safe nodes.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> adjRev[V];
        int indegree[V] = {0};

        // reverse trhe edges
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safeNodes;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adjRev[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
