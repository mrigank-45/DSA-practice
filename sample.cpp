#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int curr, int prev, vector<int> &nums, int n, vector<vector<int>> &dp)
    {
        if (curr == n - 1)
        {
            return max(nums[n - 1], nums[prev]);
        }
        if (curr == n)
        {
            return nums[prev];
        }

        if(dp[curr][prev] != -1){
            return dp[curr][prev];
        }

        int c1 = max(nums[curr], nums[curr + 1]) + solve(curr + 2, prev, nums, n, dp);
        int c2 = max(nums[prev], nums[curr]) + solve(curr + 2, curr + 1, nums, n, dp);
        int c3 = max(nums[prev], nums[curr + 1]) + solve(curr + 2, curr, nums, n, dp);

        return dp[curr][prev] = min(c1, min(c2, c3));
    }
    int minCost(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(1,0,nums,n, dp);
    }
};
