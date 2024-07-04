#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = INT_MIN;

        // right
        if (i >= 0 && i < n && j + 1 >= 0 && j + 1 < m && matrix[i][j + 1] > matrix[i][j])
        {
            ans = max(ans, solve(i, j + 1, n, m, matrix, dp));
        }
        // left
        if (i >= 0 && i < n && j - 1 >= 0 && j - 1 < m && matrix[i][j - 1] > matrix[i][j])
        {
            ans = max(ans, solve(i, j - 1, n, m, matrix, dp));
        }
        // up
        if (i - 1 >= 0 && i - 1 < n && j >= 0 && j < m && matrix[i - 1][j] > matrix[i][j])
        {
            ans = max(ans, solve(i - 1, j, n, m, matrix, dp));
        }
        // down
        if (i + 1 >= 0 && i + 1 < n && j >= 0 && j < m && matrix[i + 1][j] > matrix[i][j])
        {
            ans = max(ans, solve(i + 1, j, n, m, matrix, dp));
        }

        if (ans != INT_MIN)
        {
            return dp[i][j] = 1 + ans;
        }
        else
        {
            return dp[i][j] = 1;
        }
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, solve(i, j, n, m, matrix, dp));
            }
        }
        return ans;
    }
};
