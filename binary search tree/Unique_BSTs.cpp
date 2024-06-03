#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[20];
    int helper(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }

        int ans = 0;
        for (int k = 1; k <= n; k++)
        {
            ans += helper(k - 1) * helper(n - k);
        }
        
        return dp[n] = ans;
    }
    int numTrees(int n)
    {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};