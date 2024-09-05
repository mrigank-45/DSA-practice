#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int n, int i, int even, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }

        if (dp[i][even] != -1)
        {
            return dp[i][even];
        }

        int ans = 100001;

        if (even == 0)
        {
            if (nums[i] == 0)
            {
                nums[i] = 1;
                ans = min(ans, 1 + solve(nums, n, i + 1, 1, dp));
                nums[i] = 0;
            }
            else
            {
                ans = min(ans, solve(nums, n, i + 1, 0, dp));
            }
        }
        else
        {
            if(nums[i] == 1)
            {
                nums[i] = 0;
                ans = min(ans, 1 + solve(nums, n, i + 1, 0, dp));
                nums[i] = 1;
            }
            else
            {
                ans = min(ans, solve(nums, n, i + 1, 1, dp));
            }
        }

        return dp[i][even] = ans;
    }
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        int ans = solve(nums, n, 0, 0, dp);

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
