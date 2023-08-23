#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int memoization(string s1, string s2, int i, int j, vector<vector<int>> &dp)
    {
        if (i == s1.length() || j == s2.length())
        {
            return 0;
        }

        int ans = INT_MAX;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s1[i] == s2[j])
        {
            ans = 1 + memoization(s1, s2, i + 1, j + 1, dp);
        }
        else
        {
            int op1 = memoization(s1, s2, i + 1, j, dp);
            int op2 = memoization(s1, s2, i, j + 1, dp);
            ans = max(op1, op2);
        }

        return dp[i][j] = ans;
    }
    int tabulation(string &s1, string &s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = s1.length() - 1; i >= 0; i--)
        {
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (s1[i] == s2[j])
                {
                    ans = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    int op1 = dp[i + 1][j];
                    int op2 = dp[i][j + 1];
                    ans = max(op1, op2);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string s1, string s2)
    {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.size(), -1));
        return memoization(s1, s2, 0, 0, dp);
        return tabulation(s1, s2);
        // return space(s1,s2);
    }
};
