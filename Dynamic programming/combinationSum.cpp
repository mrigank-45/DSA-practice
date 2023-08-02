// Combination Sum 4 (leetcode)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion + memorization
    int solve(vector<int> &nums, int target, vector<int> &dp)
    {

        if (target < 0)
            return 0;

        if (target == 0)
            return 1;

        if (dp[target] != -1)
            return dp[target];

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
            ans += solve(nums, target - nums[i], dp);

        dp[target] = ans;
        return dp[target];
    }
 
    // tabulation
    int solveTab(vector<int> &nums, int target)
    {

        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {

            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0)
                    dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }

    int combinationSum4(vector<int> &nums, int target)
    {

        // For First Function solve
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);

        // For Second Function SolveTab
        return solveTab(nums, target);
    }
};
