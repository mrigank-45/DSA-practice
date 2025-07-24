#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int m, int n, vector<vector<int>> &waitCost, int i, int j, int t, vector<vector<vector<long long>>> &dp)
    {
        if (i == m - 1 && j == n - 1)
            return (i + 1) * (j + 1);

        if (dp[i][j][t] != -1)
            return dp[i][j][t];

        long long ans = LLONG_MAX;
        long long cost = (i + 1) * (j + 1);

        if (t == 1)
        {
            if (i + 1 < m)
                ans = min(ans, cost + solve(m, n, waitCost, i + 1, j, 0, dp));
            if (j + 1 < n)
                ans = min(ans, cost + solve(m, n, waitCost, i, j + 1, 0, dp));
        }
        else
        {
            long long wait = waitCost[i][j];
            if (i + 1 < m)
                ans = min(ans, cost + wait + solve(m, n, waitCost, i + 1, j, 0, dp));
            if (j + 1 < n)
                ans = min(ans, cost + wait + solve(m, n, waitCost, i, j + 1, 0, dp));
        }

        return dp[i][j][t] = ans;
    }

    long long minCost(int m, int n, vector<vector<int>> &waitCost)
    {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        return solve(m, n, waitCost, 0, 0, 1, dp);
    }
};
