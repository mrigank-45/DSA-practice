#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return BFS of given graph.
    vector<int> BFS(int V, unordered_map<int, list<int>> adj)
    {
        vector<int> ans;
        unordered_map<int, bool> vis;
        queue<int> q;

        q.push(0);
        vis[0] = true;

        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }

        return ans;
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> DFS(int node, unordered_map<int, list<int>> adj, vector<int> &ans, unordered_map<int, bool> &visited)
    {
        ans.push_back(node);
        visited[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                DFS(it, adj, ans, visited);
            }
        }
        return ans;
    }

    // if it is a disconnected graph then..
    // for (int i = 0; i < V; i++){
    //     //This for run once for each specific component of a graph
    //     if(!vis[i]){
    //         BFS() or DFS()
    //     }
    // }
};
