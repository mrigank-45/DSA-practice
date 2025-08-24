#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<vector<int>> &graph, int n, vector<int> &curr, int i)
    {
        if (i == n - 1)
        {
            ans.push_back(curr);
        }

        for (auto it : graph[i])
        {
            curr.push_back(it);
            solve(graph, n, curr, it);
            curr.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> curr;
        curr.push_back(0);
        solve(graph, n, curr, 0);

        return ans;
    }
};
