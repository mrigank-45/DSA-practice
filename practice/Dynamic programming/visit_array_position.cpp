// Visit Array Positions to Maximize Score
// need to take 2nd parameter(parity) as 1 or 0 only, not prev index as it will reduce time complexity
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long memo(int ind, vector<int> &nums, int x, int parity, vector<vector<long long>> &dp)
    {
        if (ind == nums.size())
            return 0;
        if (dp[ind][parity] != -1)
            return dp[ind][parity];
        long long ntake = memo(ind + 1, nums, x, parity, dp);
        long long take = 0;
        if (nums[ind] % 2 == parity)
            take = nums[ind] + memo(ind + 1, nums, x, parity, dp);
        else
            take = nums[ind] - x + memo(ind + 1, nums, x, nums[ind] % 2, dp);
        return dp[ind][parity] = max(take, ntake);
    }
    long long tabulation(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int parity = 0; parity <= 1; parity++)
            {
                long long ntake = dp[ind + 1][parity];
                long long take = 0;
                if (nums[ind] % 2 == parity)
                    take = nums[ind] + dp[ind + 1][parity];
                else
                    take = nums[ind] - x + dp[ind + 1][nums[ind] % 2];
                dp[ind][parity] = max(take, ntake);
            }
        }
        return dp[0][nums[0] % 2];
    }

    long long maxScore(vector<int> &nums, int x)
    {
        long long n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        int parity = nums[0] % 2;
        // return nums[0] + memo(1,nums,x,parity,dp);
        return tabulation(nums,x);
    }
};
