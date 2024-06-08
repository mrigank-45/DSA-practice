#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> adj)
    {
        vector<int> indegree(V);
        // find indegree of all nodes
        for (int i = 0; i < V; i++)
        {
            for (auto neighbour : adj[i])
            {
                indegree[neighbour]++;
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
            for (auto neighbour : adj[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
    string findOrder(string dict[], int N, int n)
    {
        // make a graph
        vector<vector<int>> adj(n);
        for (int k = 0; k < N - 1; k++)
        {
            string s1 = dict[k], s2 = dict[k + 1];
            int i = 0, l = min(s1.size(), s2.size());
            while (i < l && s1[i] == s2[i])
                i++;
            if (i != l)
            {
                // use a as 0, b as 1 and so on
                adj[s1[i] - 'a'].push_back(s2[i] - 'a');
            }
        }
        // get the topo sort fron already build function
        vector<int> ans = topoSort(n, adj);

        // make final string
        string s = "";
        for (int i = 0; i < ans.size(); i++)
        {
            s += (ans[i] + 'a');
        }
        return s;
    }
};
