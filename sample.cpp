#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int s1 = solve(grid, dp, n, m, i - 1, j);
        int s2 = solve(grid, dp, n, m, i, j - 1);
        int s3 = solve(grid, dp, n, m, i - 1, j - 1);
        int sum = s1 + s2 - s3 + grid[i][j];

        return dp[i][j] = sum;
    }
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        dp[n - 1][m - 1] = solve(grid, dp, n, m, n - 1, m - 1);

        int ans = 0;
        // transverse dp
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dp[i][j] <= k)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
