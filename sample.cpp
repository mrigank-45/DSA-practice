#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[101][101][201];
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k)
    {
        if (k == s3.size())
        {
            return (i == s1.size() && j == s2.size());
        }

        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }

        bool c1 = false, c2 = false;
        if (i < s1.size() && s1[i] == s3[k])
        {
            c1 = solve(s1, s2, s3, i + 1, j, k + 1);
        }

        if (j < s2.size() && s2[j] == s3[k])
        {
            c2 = solve(s1, s2, s3, i, j + 1, k + 1);
        }

        return dp[i][j][k] = c1 || c2;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0, 0);
    }
};
