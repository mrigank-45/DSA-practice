#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion
    int solveRec(vector<vector<char>> &matrix, int i, int j, int &maxi)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }
        int diagonal = solveRec(matrix, (i + 1), (j + 1), maxi);
        int right = solveRec(matrix, i, (j + 1), maxi);
        int down = solveRec(matrix, (i + 1), j, maxi);

        if (matrix[i][j] == '1')
        {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else
        {
            return 0;
        }
    }

    // recursion + memorization
    int solveMem(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int diagonal = solveMem(matrix, (i + 1), (j + 1), maxi, dp);
        int right = solveMem(matrix, i, (j + 1), maxi, dp);
        int down = solveMem(matrix, (i + 1), j, maxi, dp);

        if (matrix[i][j] == '1')
        {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = 0;
        }
    }

    // TABULATION
    int solveTab(vector<vector<char>> &matrix, int &maxi)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int diagonal = dp[i + 1][j + 1];
                int right = dp[i][j + 1];
                int down = dp[i + 1][j];

                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return maxi;
    }

    // SPACE OPTIMIZED SOLUTION
    int solve(vector<vector<char>> &matrix, int &maxi)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int diagonal = next[j + 1];
                int right = curr[j + 1];
                int down = next[j];

                if (matrix[i][j] == '1')
                {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return curr[0];
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        //     int maxi = 0;
        //    solveRec(matrix, 0, 0, maxi);
        //     return maxi*maxi;

        // int n = matrix.size(), m = matrix[0].size();
        // int maxi = 0;
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // solveMem(matrix, 0, 0, maxi, dp);
        // return maxi*maxi;

        // int maxi = 0;
        // solveTab(matrix, maxi);
        // return maxi*maxi;

        int maxi = 0;
        solve(matrix, maxi);
        return maxi * maxi;
    }
};
