#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int i1, int j1, int i2, int j2, vector<vector<char>> &mat, int n, int m, vector<vector<vector<vector<int>>>> &dp)
    {
        if (i1 < 0 || j1 < 0 || i2 < 0 || j2 < 0 || i1 >= n || i2 < i1 || j1 >= m || j2 < j1)
            return 0;
        if (mat[i1][j1] != mat[i2][j2])
            return 0;
        if (abs((i2 - i1) + (j2 - j1)) <= 1)
            return 1;
        if (dp[i1][j1][i2][j2] != -1)
            return dp[i1][j1][i2][j2];
        int ans = 0;
        ans = (ans + solve(i1 + 1, j1, i2, j2 - 1, mat, n, m, dp) % mod) % mod;
        ans = (ans + solve(i1 + 1, j1, i2 - 1, j2, mat, n, m, dp) % mod) % mod;
        ans = (ans + solve(i1, j1 + 1, i2, j2 - 1, mat, n, m, dp) % mod) % mod;
        ans = (ans + solve(i1, j1 + 1, i2 - 1, j2, mat, n, m, dp) % mod) % mod;
        return dp[i1][j1][i2][j2] = ans;
    }
    int countPalindromicPaths(vector<vector<char>> matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));
        return solve(0, 0, n - 1, m - 1, matrix, n, m, dp) % mod;
    }
};
