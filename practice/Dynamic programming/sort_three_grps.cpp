#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[101][4];
    int helper(vector<int> &nums, int index, int prev)
    {
        if (index == nums.size())
            return 0;
        if (dp[index][prev] != -1)
            return dp[index][prev];

        int ans = INT_MAX;
        for (int i = prev; i <= 3; i++)
        {
            if (i == nums[index])
                ans = min(ans, helper(nums, index + 1, i));
            else
                ans = min(ans, 1 + helper(nums, index + 1, i));
        }
        return dp[index][prev] = ans;
    }

    int helperTab(vector<int> &nums)
    {
        int n = nums.size();
        memset(dp, 0, sizeof(dp));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = 3; prev >= 1; prev--)
            {
                int ans = 1e9;
                for (int i = prev; i <= 3; i++)
                {
                    if (i == nums[index])
                        ans = min(ans, dp[index + 1][i]);
                    else
                        ans = min(ans, 1 + dp[index + 1][i]);
                }
                dp[index][prev] = ans;
            }
        }
        return dp[0][1];
    }

    int helperSO(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> i(4, 0);
        vector<int> next(4, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = 3; prev >= 1; prev--)
            {
                int ans = 1e9;
                for (int i = prev; i <= 3; i++)
                {
                    if (i == nums[index])
                        ans = min(ans, next[i]);
                    else
                        ans = min(ans, 1 + next[i]);
                }
                i[prev] = ans;
            }
            next = i;
        }
        return next[1];
    }

    int minimumOperations(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, 1);
        // return helperTab(nums);
        // return helperSO(nums);
    }
};
