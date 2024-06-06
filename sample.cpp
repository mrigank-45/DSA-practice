#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Fill the DP table starting from each cell
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Initialize the score for the current cell
                int score = 0;

                // Iterate over the columns to the right
                for (int k = j + 1; k < m; k++)
                {
                    score += grid[i][k] - grid[i][k - 1];
                    dp[i][k] = max(dp[i][k], dp[i][k - 1] + score);
                }

                // Reset the score
                score = 0;

                // Iterate over the rows below
                for (int k = i + 1; k < n; k++)
                {
                    score += grid[k][j] - grid[k - 1][j];
                    dp[k][j] = max(dp[k][j], dp[k - 1][j] + score);
                }
            }
        }

        // The answer will be stored in the bottom-right cell of the DP table
        return dp[n - 1][m - 1];
    }
};
