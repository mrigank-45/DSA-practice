#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int i, vector<int> &dp)
    {
        if (i == nums.size() - 1)
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int ans = 10000;
        for (int j = 1; j <= nums[i] && i + j < nums.size(); j++)
        {
            if ((nums[i + j] == 0 && i + j == nums.size() - 1) || nums[i+j] != 0)
            {
                ans = min(ans, 1 + solve(nums, i + j, dp));
            }
        }
        return dp[i] = ans;
    }
    int jump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
