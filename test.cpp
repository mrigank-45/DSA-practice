#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j, int n, int m, int score, vector<vector<int>> &dp)
    {
        int ans = INT_MIN;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        for (int k = j + 1; k < m; k++)
        {
            ans = max(ans, score + grid[i][k] - grid[i][j]);
            ans = max(ans, solve(grid, i, k, n, m, score + grid[i][k] - grid[i][j], dp));
        }

        for (int k = i + 1; k < n; k++)
        {
            ans = max(ans, score + grid[k][j] - grid[i][j]);
            ans = max(ans, solve(grid, k, j, n, m, score + grid[k][j] - grid[i][j], dp));
        }

        return dp[i][j] = ans;
    }

    int maxScore(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<vector<int>> dp(n, vector<int>(m, -1));
                ans = max(ans, solve(grid, i, j, n, m, 0, dp));
            }
        }

        return ans;
    }
};
