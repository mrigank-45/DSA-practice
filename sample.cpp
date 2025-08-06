#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, vector<int> &nums, int n, vector<int> &dp)
    {
        if (i == n)
            return 0;

        if (dp[i] != -1)
        {
            return dp[i];
        }
        // not pick
        int j = i;
        while (j < n && nums[j] == nums[j + 1])
            j++;
        int c1 = solve(j + 1, nums, n, dp);

        // pick
        int points = nums[i];
        j = i;
        while (j < n && nums[j] == nums[j + 1])
        {
            points += nums[j];
            j++;
        }
        j++;
        while (j < n && nums[j] == nums[i] - 1)
            j++;
        int c2 = points + solve(j, nums, n, dp);

        return dp[i] = max(c1, c2);
    }
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        sort(nums.rbegin(), nums.rend());

        vector<int> dp(n + 1, -1);

        return solve(0, nums, n, dp);
    }
};
