#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &word1, string &word2, int n, int m, vector<vector<int>> &dp, int i, int j)
    {
        if (i == n)
        {
            return m - j;
        }
        if(j == m)
        {
            return n - i;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(word1[i] == word2[j])
        {
            return dp[i][j] = solve(word1, word2, n, m, dp, i + 1, j + 1);
        }

        int op1 = 1 + solve(word1, word2, n, m, dp, i, j + 1);
        int op2 = 1 + solve(word1, word2, n, m, dp, i + 1, j);

        return dp[i][j] = min(op1, op2);
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(word1, word2, n, m, dp, 0, 0);
    }
};
