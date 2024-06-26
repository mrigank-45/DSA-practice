// In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

// ALGO: we just have to push the node into stack while coming back from it's DFS, we have the desired order. (uses DFS)
// Applicable to directed acyclic graphs.
// TC: O(V + E)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, int vis[], stack<int> &st,
             vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, vis, st, adj);
        }
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
