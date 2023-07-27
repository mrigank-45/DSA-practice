// ALGO: Find indegree of all nodes and initially push into queue all nodes where (indegree = 0), till queue is not empty keep decreasing indegree of neighbours by 1 and 
// push into queue if (indegree = 0). For no cycle, ans.size() == n.

// Applicable to directed acyclic graphs (uses BFS) // can detect cycle using this

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V);
        // find indegree of all nodes
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        // push nodes if indegree is 0
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // reduce the indegree of neighbours by 1
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return ans;

        // we can also detect cycle in the graph using this
        if (ans.size() == V)
        {
            cout << "no cycle present" << endl;
        }
        else
        {
            cout << "cycle is present" << endl;
        }
    }
};
