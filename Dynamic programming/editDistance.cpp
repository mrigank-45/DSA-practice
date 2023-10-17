// Edit Distance (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion + memorization
    int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp)
    {
        if (word2.size() == j)
            return word1.size() - i;
        if (word1.size() == i)
            return word2.size() - j;

        if (dp[i][j] != -1)
            return dp[i][j];

        // 3 possibilities
        int a = INT_MAX;

        if (word2[j] == word1[i])
        {
            a = solve(word1, word2, i + 1, j + 1, dp); // skip if same
        }

        int b = solve(word1, word2, i + 1, j + 1, dp) + 1; // replace

        int c = solve(word1, word2, i + 1, j, dp) + 1; // delete

        int d = solve(word1, word2, i, j + 1, dp) + 1; // insert

        dp[i][j] = min(a, min(b, min(c, d))); // min of all
        return dp[i][j];
    }

    // tabulation
    int solve1(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> h(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i < m + 1; i++)
        {
            h[n][i] = m - i;
        }
        for (int i = 0; i < n + 1; i++)
        {
            h[i][m] = n - i;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int a = INT_MAX;
                if (word1[i] == word2[j])
                {
                    a = h[i+1][j+1];
                }
                else
                {
                    int b = 1 + h[i+1][j+1]; // replace

                    int c = 1 + h[i+1][j+1]; // delete

                    int d = 1 + h[i+1][j+1]; // insert

                    h[i][j] = min(a, min(b, min(c, d)));
                }
            }
        }
        return h[0][0];
    }

    // can be space optamized

    int minDistance(string word1, string word2)
    {

        int m = word1.size(), n = word2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(word1, word2, 0, 0, dp);
    }
};
