// Longest Common Substring (codeStudio)
// just some change in approach in longestSubsequence.cpp tabulation solution and we get this
// we cannot solve it in memo as 3 variables will be changing (i,j,count).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tabulation(string &str1, string &str2)
    {
        // Creating 'DP' table, initialize as 0
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

        // Variable to store the answer.
        int ans = 0;

        // Iterate through first string.
        for (int i = str1.length() - 1; i >= 0; i--)
        {
            // Iterate through second string.
            for (int j = str2.size() - 1; j >= 0; j--)
            {
                // If characters are same at 'i' and 'j' then add 1 to the answer obtained from rest of the string.
                if (str1[i] == str2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    // set as 0 as no substring can be formed
                    dp[i][j] = 0;
                }
            }
        }
        // Return the answer.
        return ans;
    }
};
