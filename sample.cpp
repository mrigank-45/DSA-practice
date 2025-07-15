#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int prev, int flag, vector<int> &nums, int n)
    {
        if (i == n)
            return 0;

        if (dp[i][prev][flag] != -1)
            return dp[i][prev][flag];

        int ans = 0;

        // pick
        if (prev == n)
        {
            ans = max(ans, 1 + solve(i + 1, i, 0, nums, n));
        }
        else if (flag == 0)
        {
            if (nums[i] - nums[prev] > 0)
                ans = max(ans, 1 + solve(i + 1, i, 1, nums, n));

            else if (nums[i] - nums[prev] < 0)
                ans = max(ans, 1 + solve(i + 1, i, 2, nums, n));
        }
        else if (flag == 1 && nums[i] - nums[prev] < 0)
        {
            ans = max(ans, 1 + solve(i + 1, i, 2, nums, n));
        }
        else if (flag == 2 && nums[i] - nums[prev] > 0)
        {
            ans = max(ans, 1 + solve(i + 1, i, 1, nums, n));
        }

        // not pick
        ans = max(ans, solve(i + 1, prev, flag, nums, n));

        return dp[i][prev][flag] = ans;
    }

    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();

        dp.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(3, -1)));

        return solve(0, n, 0, nums, n);
    }
};
