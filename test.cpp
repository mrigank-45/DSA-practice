#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int n, int k, int i, int prev, vector<vector<vector<int>>> &dp)
    {
        if (i == n)
        {
            return 0;
        }

        if (dp[i][prev][k] != -1)
        {
            return dp[i][prev][k];
        }

        int ans = INT_MIN;

        // choose
        if (prev != n && nums[i] == nums[prev])
        {
            ans = max(ans, 1 + solve(nums, n, k, i + 1, i, dp));
        }
        else if (prev != n && nums[i] != nums[prev] && k > 0)
        {
            ans = max(ans, 1 + solve(nums, n, k - 1, i + 1, i, dp));
        }
        else if (prev == n)
        {
            ans = max(ans, 1 + solve(nums, n, k, i + 1, i, dp));
        }

        // not choose
        ans = max(ans, solve(nums, n, k, i + 1, prev, dp));

        return dp[i][prev][k] = ans;
    }
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1)));

        return solve(nums, n, k, 0, n, dp);
    }
};
