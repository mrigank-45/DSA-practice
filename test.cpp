#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<pair<short, short>> dir = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    double solve(int n, int k, int i, int j, vector<vector<vector<double>>> &dp)
    {
        if (i < 0 || j < 0 || j >= n || i >= n)
            return 0;
        if (k == 0)
            return 1;
        if (dp[k][i][j] != -1)
            return dp[k][i][j];
        double ans = 0;
        for (short p = 0; p < 8; p++)
        {
            ans += solve(n, k - 1, i + dir[p].first, j + dir[p].second, dp);
        }
        return dp[k][i][j] = ans;
    }

public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1)));
        return solve(n, k, row, column, dp) / pow(8, k);
    }
};