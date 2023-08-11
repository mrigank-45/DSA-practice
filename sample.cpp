#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int buy, vector<vector<int>> &dp, vector<int> &prices)
    {
        if (index == prices.size() || buy >= 4)
        {
            return 0;
        }
        if (dp[index][buy] != -1)
        {
            return dp[index][buy];
        }

        if (buy == 0 || buy == 2)
        {
            return dp[index][buy] = max((-1) * prices[index] + solve(index + 1, buy + 1, dp, prices), solve(index + 1, buy, dp, prices));
        }
        else
        {
            return dp[index][buy] = max(prices[index] + solve(index + 1, buy + 1, dp, prices), solve(index + 1, buy, dp, prices));
        }
    }

    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -1));
        return solve(0, 0, dp, prices);
    }
};
