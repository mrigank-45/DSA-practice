// Longest Repeating Subsequence | GFG
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &dp, int n)
    {
        if (i == n || j ==n)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans;
        if (str1[i] == str2[j] && i != j)
        { 
            // take both for s1 and s2 since equal and index not same
            ans = 1 + solve(i + 1, j + 1, str1, str2, dp, n);
        }
        else
        {
            // take for s1
            int c1 = solve(i + 1, j, str1, str2, dp, n);
            // take for s2
            int c2 = solve(i, j + 1, str1, str2, dp, n);

            ans = max(c1, c2);
        }

        return dp[i][j] = ans;
    }
    int LongestRepeatingSubsequence(string str)
    {
        int n = str.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, str, str, dp, n);
    }
};
