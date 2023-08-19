// Unique Paths II (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool allowed(vector<vector<int>> &grid, int n, int m, int i, int j)
    {
        if (i <= n - 1 && j <= m - 1 && grid[i][j] == 0)
        {
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>> &grid, int n, int m, int i, int j, vector<vector<int>> dp)
    {
        // base case
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = 0;
        int down = 0;
        if (allowed(grid, n, m, i, j + 1))
        {
            right = solve(grid, n, m, i, j + 1, dp);
        }
        if (allowed(grid, n, m, i + 1, j))
        {
            down = solve(grid, n, m, i + 1, j, dp);
        }

        return dp[i][j] = right + down;
    }

    int solve1(vector<vector<int>> &grid)
    {

        long long int n = grid.size();
        long long int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        {
            return 0;
        }

        vector<vector<long long int>> dp(n + 1, vector<long long int>(m + 1, -1)); 

        dp[n - 1][m - 1] = 1;

        // start the loops from n-1 to set value for [n-1][m-1] and [n-2][m-1]
        for (long long int i = n - 1; i >= 0; i--)
        {
            for (long long int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    long long int right = 0;
                    long long int down = 0;
                    if (allowed(grid, n, m, i, j + 1))
                    {
                        right = dp[i][j + 1];
                    }
                    if (allowed(grid, n, m, i + 1, j))
                    {
                        down = dp[i + 1][j];
                    }
                    dp[i][j] = right + down;
                }
            }
        }

        return dp[0][0];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solve(obstacleGrid, n, m, 0, 0, dp);

        return solve1(obstacleGrid);
    }
};
