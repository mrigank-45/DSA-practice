// Rod cutting problem (codingNinja)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, vector<int> &price, int n, int lastIndex, vector<vector<int>> dp)
    {
        // base case
        if (i >= n)
        {
            return 0;
        }

        if (dp[i][lastIndex] != -1)
        {
            return dp[i][lastIndex];
        }

        int cut = price[i - lastIndex] + solve(i + 1, price, n, i + 1, dp);
        int nocut = solve(i + 1, price, n, lastIndex, dp);

        return dp[i][lastIndex] = max(cut, nocut);
    }

    // giving error, don't know why
    int solve1(vector<int> &price, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= n + 1; i++)
        {
            dp[n][i] = 0;
            dp[n + 1][i] = 0;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n; j >= 0; j--)
            {
                int cut = 0;
                if (i - j < n && i - j >= 0)
                {
                    cut = price[i - j] + dp[i + 1][i + 1];
                }

                int nocut = dp[i + 1][j];

                dp[i][j] = max(cut, nocut);
            }
        }

        return dp[0][0];
    }

    int cutRod(vector<int> &price, int n)
    {
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solve(0, price, n, 0, dp);

        return solve1(price, n);
    }
};
