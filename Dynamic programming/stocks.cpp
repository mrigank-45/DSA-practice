// Best Time to Buy and Sell Stock II (leetcode)
// In Qs of bus and sell at most 2 times or k time, change the value of buy accordingly in condition and base case

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // recursion + memo
    int solve(int index, int buy, vector<vector<int>> &dp, vector<int> &prices)
    {
        if (index == prices.size())
        {
            return 0;
        }
        if (dp[index][buy] != -1)
        {
            return dp[index][buy];
        }

        if (buy)
        {
            // max(buy or skip)
            return dp[index][buy] = max((-1) * prices[index] + solve(index + 1, 0, dp, prices), solve(index + 1, 1, dp, prices));
        }
        else
        {
            // max(sell or skip)
            return dp[index][buy] = max(prices[index] + solve(index + 1, 1, dp, prices), solve(index + 1, 0, dp, prices));
        }
    }

    // tabulation
    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j >= 0; j--)
            {
                if (j)
                {
                    dp[i][j] = max((-1) * prices[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                else
                {
                    dp[i][j] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
    // can optamize space using just 2 vectors (curr and next)

    // main func
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, dp, prices);
    }
};
