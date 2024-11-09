#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int n, int i, int prev, int flag, vector<vector<vector<int>>> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if(dp[i][prev][flag] != -1)
        {
            return dp[i][prev][flag];
        }
        int ans = 0;

        // choose
        if (prev == 0)
        {
            if (i == 0)
            {
                ans = max(ans, nums[i] + solve(nums, n, i + 1, 1, 1, dp));
            }
            else if (i == n - 1)
            {
                if (flag == 0)
                {
                    ans = max(ans, nums[i] + solve(nums, n, i + 1, 1, flag, dp));
                }
            }
            else
            {
                ans = max(ans, nums[i] + solve(nums, n, i + 1, 1, flag, dp));
            }
        }

        // not choose
        ans = max(ans, solve(nums, n, i + 1,0, flag, dp));

        return dp[i][prev][flag] = ans;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));

        return solve(nums, n, 0, 0, 0, dp);
    }
};
