#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion
    int solve1(int n)
    {
        if (n == 0)
            return 0;

        int ans = INT_MAX;
        for (int i = 0; i * i <= n; i++)
        {
            ans = min(ans, 1 + solve1(n - i * i));
        }

        return ans;
    }

    // recursion + memorization
    int solve2(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans = INT_MAX;

        for (int i = 0; i * i <= n; i++)
        {
            ans = min(ans, 1 + solve2(n - i * i, dp));
        }

        dp[n] = ans;
        return dp[n];
    }
    
    // tabulation
    int solve3(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }

    int numSquares(int n)
    {

        return solve1(n);

        vector<int> dp(n + 1, -1);
        return solve2(n, dp);

        return solve3(n);
    }
};
