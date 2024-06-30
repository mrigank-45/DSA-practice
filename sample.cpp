#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(vector<vector<int>> &grid, int i, int j, vector<vector<vector<int>>> &dp)
    {
        if (dp[i][j][0] != -1)
        {
            return dp[i][j];
        }
        int right = 0, left = 0, up = 0, down = 0;
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1)
        {
            right = solve(grid, i, j + 1, dp)[0];
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1)
        {
            left = solve(grid, i, j - 1, dp)[1];
        }
        if (i - 1 >= 0 && grid[i - 1][j] == 1)
        {
            up = solve(grid, i - 1, j, dp)[2];
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == 1)
        {
            down = solve(grid, i + 1, j, dp)[3];
        }

        dp[i][j] = {right + 1, left + 1, up + 1, down + 1};

        return dp[i][j];
    }
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4, -1)));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && dp[i][j][0] == -1)
                {
                    vector<int> v = solve(grid, i, j, dp);
                    dp[i][j] = v;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int right = dp[i][j][0];
                    int left = dp[i][j][1];
                    int up = dp[i][j][2];
                    int down = dp[i][j][3];

                    // for right and down
                    int temp = min(right, down);
                    if (i + temp - 1 < n && j + temp - 1 < n && dp[i + temp - 1][j + temp - 1][1] >= temp && dp[i + temp - 1][j + temp - 1][2] >= temp)
                    {
                        ans = max(ans, temp);
                    }

                    // for left and down
                    temp = min(left, down);
                    if (i - temp + 1 >= 0 && j - temp + 1 >= 0 && dp[i - temp + 1][j - temp + 1][0] >= temp && dp[i - temp + 1][j - temp + 1][3] >= temp)
                    {
                        ans = max(ans, temp);
                    }
                }
            }
        }

        return ans;
    }
};
