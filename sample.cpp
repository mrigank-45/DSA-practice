#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int n, int m, int i, int prev, map<int, vector<pair<int, int>>> &mp,  vector<map<int, int>> &dp)
    {
        if (i == m)
        {
            return 0;
        }

        if (dp[i].count(prev))
        {
            return dp[i][prev];
        }

        int ans = INT_MAX;

        for (auto it : mp[i])
        {
            int a = it.first;
            int b = it.second;
            if (a != prev)
            {
                ans = min(ans, (n - b) + solve(grid, n, m, i + 1, a, mp, dp));
            }
        }
        ans = min(ans, n + solve(grid, n, m, i + 1, -1, mp, dp));

        return dp[i][prev] = ans;
    }
    int minimumOperations(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        map<int, vector<pair<int, int>>> mp;

        for (int i = 0; i < m; i++)
        {
            vector<pair<int, int>> v;
            map<int, int> mp1;
            for (int j = 0; j < n; j++)
            {
                mp1[grid[j][i]]++;
            }
            for (auto it : mp1)
            {
                v.push_back({it.first, it.second});
            }
            mp[i] = v;
        }

        vector<map<int, int>> dp(m + 1, map<int, int>());

        return solve(grid, n, m, 0, -1, mp, dp);
    }
};
