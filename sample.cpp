#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> dp)
    {
        if (i == -1 || j == -1)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s1[i] == s2[j])
        {
            return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
        }
        else
        {
            return dp[i][j] = max(solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp));
        }
    }
    int tabulation1(int n1, int n2, string s1, string s2)
    {
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0)); 

        for (int i = 1; i <= n1; i++) 
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1]) 
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; 
                }
                else 
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
                }
            }
        }

        return dp[n1][n2]; // Length of LCS
    }
    int tabulaton(int n1, int n2, string s1, string s2)
    {
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        // calls
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (i == 0 || j == 0)
                {
                    if (s1[i] == s2[j])
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        if (i == 0 && j != 0)
                        {
                            dp[i][j] = dp[i][j - 1];
                        }
                        else if (j == 0 && i != 0)
                        {
                            dp[i][j] = dp[i - 1][j];
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
                else
                {
                    if (s1[i] == s2[j])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }

        return dp[n1 - 1][n2 - 1];
    }

    int longestPalindromeSubseq(string s)
    {
        string s1 = s;
        string s2 = s;

        reverse(s2.begin(), s2.end());

        int n1 = s1.size();
        int n2 = s2.size();

        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        // dp[i][j] = solve(n1 - 1, n2 - 1, s1, s2, dp);

        return tabulaton(n1, n2, s1, s2);
    }
};
