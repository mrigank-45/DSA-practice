// Visit Array Positions to Maximize Score

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

    // gives TLE, even though same solution
    // long long solve(vector<int> &nums, int x, int prev, int i, vector<vector<int>> dp)
    // {
    //     if (i >= nums.size())
    //     {
    //         return 0;
    //     }

    //     if(dp[prev][i] != -1){
    //         return dp[prev][i];
    //     }

    //     long long include = 0, exclude = 0;

    //     // parity check
    //     if (nums[prev] % 2 == nums[i] % 2)
    //     {
    //         include = nums[i] + solve(nums, x, i, i + 1, dp);
    //     }
    //     else
    //     {
    //         include = nums[i] - x + solve(nums, x, i, i + 1, dp);
    //     }
    //     exclude = solve(nums, x, prev, i + 1, dp);

    //     return dp[prev][i] = max(include, exclude);
    // }

    // long long tabulation1(vector<int> &nums, int x)
    // {
    //     // DP array
    //     vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        
    //     // base case 
    //     for (int i = 0; i < nums.size() + 1; i++)
    //     {
    //         dp[i][nums.size()] = 0;
    //     }

    //     for(int i = nums.size() - 1; i >= 0; i--){
    //         for(int j = nums.size() - 1; j >= 1; j--){
    //             long long include = 0, exclude = 0;

    //             // parity check
    //             if (nums[i] % 2 == nums[j] % 2)
    //             {
    //                 include = nums[j] + dp[j][j + 1];
    //             }
    //             else
    //             {
    //                 include = nums[j] - x + dp[j][j + 1];
    //             }
    //             exclude = dp[i][j + 1];

    //             dp[i][j] = max(include, exclude);
    //         }
    //     }

    //     return dp[0][1];
    // }

    long long maxScore(vector<int> &nums, int x)
    {
        long long n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        int parity = nums[0] % 2;
        // return nums[0] + memo(1,nums,x,parity,dp);
        return tabulation(nums,x);
    }
};
