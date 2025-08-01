#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(unordered_map<int, vector<int>> mp, int k, int node)
    {
        if (k < 0)
            return 0;
        int ans = 0;
        queue<int> q;
        q.push(node);
        unordered_set<int> visited;
        while (!q.empty())
        {
            int size = q.size();
            ans += size;
            for (int i = 0; i < size; i++)
            {
                int temp = q.front();
                q.pop();
                visited.insert(temp);
                for (auto it : mp[temp])
                {
                    if (visited.find(it) != visited.end())
                        continue;
                    q.push(it);
                }
            }
            k--;
            if (k < 0)
                break;
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        unordered_map<int, vector<int>> mp1;
        unordered_map<int, vector<int>> mp2;

        for (int i = 0; i < n - 1; i++)
        {
            mp1[edges1[i][0]].push_back(edges1[i][1]);
            mp1[edges1[i][1]].push_back(edges1[i][0]);
        }

        for (int i = 0; i < m - 1; i++)
        {
            mp2[edges2[i][0]].push_back(edges2[i][1]);
            mp2[edges2[i][1]].push_back(edges2[i][0]);
        }

        int maxi = 0;
        for (int i = 0; i < m; i++)
        {
            if (k < 0)
                break;
            maxi = max(maxi, bfs(mp2, k - 1, i));
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(bfs(mp1, k, i) + maxi);
        }
        return ans;
    }
};
