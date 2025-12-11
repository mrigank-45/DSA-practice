#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
                adj[s1[i] - 'a'].push_back(s2[i] - 'a');
            }
        }
        vector<int> ans = topoSort(n, adj);
        string s = "";
        for (int i = 0; i < ans.size(); i++)
        {
            s += (ans[i] + 'a');
        }
        return s;
    }
};
