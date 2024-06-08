#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int price[], int i, int len, int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }

        if (dp[i][len] != -1)
        {
            return dp[i][len];
        }

        int ans;
        int c1 = price[len - 1] + solve(price, i, 0, n, dp);
        int c2 = solve(price, i + 1, len + 1, n, dp);

        ans = max(c1, c2);

        return dp[i][len] = ans;
    }
    int cutRod(int price[], int n)
    {
        // 2d DP
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(price, 0, 1, n, dp);
    }
};
