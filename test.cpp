#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int i, vector<int> &dp)
    {

        if (i == n)
        {
            return 1;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int a = 0, b = 0;

        // 1 step
        if (i + 1 <= n)
        {
            a = solve(n, i + 1, dp);
        }

        // 2 step
        if (i != 0 && i + 2 <= n)
        {
            b = solve(n, i + 2, dp);
        }

        return dp[i] = a + b;
    }
    int tabulation(int n)
    {
        vector<int> dp(n + 1, -1);

        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            int a = 0, b = 0;

            // 1 step
            if (i + 1 <= n)
            {
                a = dp[i + 1];
            }

            // 2 step
            if (i != 0 && i + 2 <= n)
            {
                b = dp[i + 2];
            }

            dp[i] = a + b;
        }

        return dp[0];
    }
    int nthPoint(int n)
    {
        vector<int> dp(n + 1, -1);

        return solve(n, 0, dp);
    }
};
