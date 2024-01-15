#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int target, int index, vector<int> dp)
    {
        if (index >= nums.size())
        {
            return -1;
        }
        if (index == nums.size() - 1)
        {
            return 0;
        }

        if (dp[index] != -2)
        {
            return dp[index];
        }

        int ans = -1;

        for (int i = index + 1; i < nums.size(); i++)
        {
            if (abs(nums[index] - nums[i]) <= target)
            {
                if (solve(nums, target, i, dp) != -1)
                {
                    ans = max(ans, 1 + solve(nums, target, i, dp));
                }
            }
        }

        return dp[index] = ans;
    }
    int tabuation(vector<int> &nums, int target)
    {
        vector<int> dp(nums.size(), -2);

        dp[nums.size() - 1] = 0;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            int ans = -1;

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (abs(nums[i] - nums[j]) <= target)
                {
                    if (dp[j] != -1)
                    {
                        ans = max(ans, 1 + dp[j]);
                    }
                }
            }

            dp[i] = ans;
        }

        return dp[0];
    }
    int maximumJumps(vector<int> &nums, int target)
    {
        vector<int> dp(nums.size(), -2);
        return solve(nums, target, 0, dp);
    }
};
