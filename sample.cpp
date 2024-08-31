#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[502][502][26];
    int solve(vector<int> &nums, int n, int k, int i, int prev)
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
        if (prev != 501 && nums[i] == nums[prev])
        {
            ans = max(ans, 1 + solve(nums, n, k, i + 1, i));
        }
        else if (prev != 501 && nums[i] != nums[prev] && k > 0)
        {
            ans = max(ans, 1 + solve(nums, n, k - 1, i + 1, i));
        }
        else if (prev == 501)
        {
            ans = max(ans, 1 + solve(nums, n, k, i + 1, i));
        }

        // not choose
        ans = max(ans, solve(nums, n, k, i + 1, prev));

        return dp[i][prev][k] = ans;
    }
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(nums, n, k, 0, 501);
    }
};
