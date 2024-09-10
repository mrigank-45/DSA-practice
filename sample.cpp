#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &nums, int n, int i, int flag, vector<vector<long long>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if(dp[i][flag] != -1)
        {
            return dp[i][flag];
        }
        long long split, notSplit;

        if (flag == 1)
        {
            // split
            split = nums[i] + solve(nums, n, i + 1, 1, dp);

            // not split
            notSplit = nums[i] + solve(nums, n, i + 1, 0, dp);
        }
        else
        {
            // split
            split = ((-1) * nums[i]) + solve(nums, n, i + 1, 1, dp);

            // not split
            notSplit = ((-1) * nums[i]) + solve(nums, n, i + 1, 1, dp);
        }

        return dp[i][flag] = max(split, notSplit);
    }
    long long maximumTotalCost(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        return solve(nums, n, 0, 1, dp);
    }
};
