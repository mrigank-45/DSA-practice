#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &r, vector<int> &q)
    {
        int n = q.size();
        vector<int> adj[n];
        vector<int> ind(n, 0);
        for (auto it : r)
        {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        queue<int> qu;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0)
                qu.push(i);
            ans[i] = i;
        }
        while (!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            for (auto it : adj[node])
            {
                if (q[node] < q[it])
                {
                    q[it] = q[node];
                    ans[it] = ans[node];
                }
                ind[it]--;
                if (ind[it] == 0)
                    qu.push(it);
            }
        }
        return ans;
    }
};
