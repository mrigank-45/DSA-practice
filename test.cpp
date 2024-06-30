#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][101][2];
    int solve(vector<int> &prices, int i, int k, int buy, int n)
    {
        if (i == n || k == 0)
        {
            return 0;
        }
        if (dp[i][k][buy] != -1)
        {
            return dp[i][k][buy];
        }

        if (buy)
        {
            return dp[i][k][buy] = max(-prices[i] + solve(prices, i + 1, k, 0, n), solve(prices, i + 1, k, 1, n));
        }
        else
        {
            return dp[i][k][buy] = max(prices[i] + solve(prices, i + 1, k - 1, 1, n), solve(prices, i + 1, k, 0, n));
        }
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, k, 1, n);
    }
};
