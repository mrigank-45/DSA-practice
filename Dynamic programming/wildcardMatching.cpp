#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // recursion + memo
    // we are solving in 1-based indexing in memo so that we can write tabulation method base case
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        // base cases
        if (i == 0 && j == 0)
            return true;

        if (i > 0 && j == 0)
            return false;

        if (i == 0 && j > 0)
        {
            for (int k = 1; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // step 2
        if (dp[i][j] != -1)
            return dp[i][j];

        // step 3
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }
        else if (p[j - 1] == '*')
        {
            bool a = solve(i, j - 1, s, p, dp); // replace * with empty string
            bool b = solve(i - 1, j, s, p, dp); // replace * with *a (a means char in s[i])

            return dp[i][j] = a || b;
        }
        else
        {
            return dp[i][j] = 0;
        }
    }

    // tabulation
    bool solve1(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;
        for (int k = 1; k <= m; k++)
        {
            if (p[k - 1] == '*')
                dp[0][k] = true;
            else
                break;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
    // can ne space optamized using 2 vectors(prev and curr)

public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n - 1, m - 1, s, p, dp);
    }
};
