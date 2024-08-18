#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m, n;
    vector<vector<int>> dp;
    int ans = INT_MIN;

    int solve(vector<vector<int>> &grid, int i, int j, int score)
    {
        if (dp[i][j] != INT_MIN)
        {
            return dp[i][j] + score;
        }

        int maxScore = score;

        for (int x = j + 1; x < n; ++x)
        {
            int newScore = solve(grid, i, x, score + grid[i][x] - grid[i][j]);
            maxScore = max(maxScore, newScore);
        }

        for (int y = i + 1; y < m; ++y)
        {
            int newScore = solve(grid, y, j, score + grid[y][j] - grid[i][j]);
            maxScore = max(maxScore, newScore);
        }

        dp[i][j] = maxScore - score;

        return maxScore;
    }

    int maxScore(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<int>(n, INT_MIN));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int x = j + 1; x < n; ++x)
                {
                    ans = max(ans, solve(grid, i, x, grid[i][x] - grid[i][j]));
                }

                for (int y = i + 1; y < m; ++y)
                {
                    ans = max(ans, solve(grid, y, j, grid[y][j] - grid[i][j]));
                }
            }
        }

        return ans;
    }
};
