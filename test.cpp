#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int curr, vector<int> &rewardValues, int n, vector<vector<int>> &dp)
    {
        if (i < 0)
        {
            return 0;
        }

        if (dp[i][curr] != -1)
        {
            return dp[i][curr];
        }

        // not choose
        int res = solve(i - 1, curr, rewardValues, n, dp);

        // choose
        if (rewardValues[i] < curr)
        {
            res = max(res, rewardValues[i] + solve(i - 1, min(curr - rewardValues[i],rewardValues[i]), rewardValues, n, dp));
        }
        else if (curr == 0)
        {
            res = max(res, rewardValues[i] + solve(i - 1, rewardValues[i], rewardValues, n, dp));
        }

        return dp[i][curr] = res;
    }
    int maxTotalReward(vector<int> &rewardValues)
    {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());

        int max_value = *max_element(rewardValues.begin(), rewardValues.end());

        // 2d DP
        vector<vector<int>> dp(n + 1, vector<int>(max_value + 1, -1));

        return solve(n-1, 0, rewardValues, n, dp);
    }
};
