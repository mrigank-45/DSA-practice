#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string s, int i, int j, vector<vector<int>> dp)
    {
        if (i >= j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == s[j])
        {
            return dp[i][j] = solve(s, i + 1, j - 1, dp);
        }
        else
        {
            return dp[i][j] = 1 + min(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
        }
    }
    int tabulation(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // base case
        for(int i = 0; i < n + 1; i++)
        {
            for(int j = 0; j < n + 1; j++)
            {
                if(i>=j){
                    dp[i][j] = 0;
                }
            }
        }
        
        // table fill
        for (int gap = 1; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
    int minInsertions(string s)
    {
        int n = s.size();

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(s, 0, n - 1, dp);

        return tabulation(s);
    }
};
