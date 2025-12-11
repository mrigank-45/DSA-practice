#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoization solution | gives TLE | cannot convert it to tabulation
    int memo(vector<vector<int>> &grid, int i, int j, int n, int m, int score, vector<vector<int>> &dp)
    {
        int ans = INT_MIN;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        for (int k = j + 1; k < m; k++)
        {
            ans = max(ans, score + grid[i][k] - grid[i][j]);
            ans = max(ans, memo(grid, i, k, n, m, score + grid[i][k] - grid[i][j], dp));
        }

        for (int k = i + 1; k < n; k++)
        {
            ans = max(ans, score + grid[k][j] - grid[i][j]);
            ans = max(ans, memo(grid, k, j, n, m, score + grid[k][j] - grid[i][j], dp));
        }

        return dp[i][j] = ans;
    }

    // Direct Tabulation solution
    // Here each cell represented the maximum cost that can be achieved if it was the destination cell.
    // link for logic: https://leetcode.com/problems/maximum-difference-score-in-a-grid/solutions/5148658/c-basic-dp-approach-tabulation/
    int tabulation(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 0;
        int c1, c2;
        int res = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                if (i == 0)
                {
                    dp[i][j] = max(grid[i][j] - grid[i][j - 1], grid[i][j] - grid[i][j - 1] + dp[i][j - 1]);
                    res = max(res, dp[i][j]);
                }
                else if (j == 0)
                {
                    dp[i][j] = max(grid[i][j] - grid[i - 1][j], grid[i][j] - grid[i - 1][j] + dp[i - 1][j]);
                    res = max(res, dp[i][j]);
                }
                else
                {
                    c1 = max(dp[i][j - 1] + grid[i][j] - grid[i][j - 1], dp[i - 1][j] + grid[i][j] - grid[i - 1][j]); // assuming it as the last move of a series of moves
                    c2 = max(grid[i][j] - grid[i][j - 1], grid[i][j] - grid[i - 1][j]);  // assuming it as a new move
                    dp[i][j] = max(c1, c2);
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
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
                ans = max(ans, memo(grid, i, j, n, m, 0, dp));
            }
        }

        return ans;
    }
};
