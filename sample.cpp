#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int n, int i, vector<int> &dp)
    {
        if (i == n - 2)
        {
            if (nums[i] == 1 && nums[i + 1] == 1)
            {
                return 0;
            }
            else
            {
                return 100000;
            }
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int ans = 100000;

        if (nums[i] == 0)
        {
            nums[i] = 1;
            if (nums[i + 1] == 0)
            {
                nums[i + 1] = 1;
            }
            else
            {
                nums[i + 1] = 0;
            }
            if (nums[i + 2] == 0)
            {
                nums[i + 2] = 1;
            }
            else
            {
                nums[i + 2] = 0;
            }
            ans = min(ans, 1 + solve(nums, n, i + 1, dp));
            nums[i] = 0;
            if (nums[i + 1] == 0)
            {
                nums[i + 1] = 1;
            }
            else
            {
                nums[i + 1] = 0;
            }
            if (nums[i + 2] == 0)
            {
                nums[i + 2] = 1;
            }
            else
            {
                nums[i + 2] = 0;
            }
        }
        else
        {
            ans = min(ans, solve(nums, n, i + 1, dp));
        }

        return dp[i] = ans;
    }
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        int ans = solve(nums, n, 0, dp);

        if (ans >= 100000)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};
