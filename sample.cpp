#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &nums, int x, int prev, int i, vector<vector<int>> dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }

        if(dp[prev][i] != -1){
            return dp[prev][i];
        }

        long long include = 0, exclude = 0;

        // parity check
        if (nums[prev] % 2 == nums[i] % 2)
        {
            include = nums[i] + solve(nums, x, i, i + 1, dp);
        }
        else
        {
            include = nums[i] - x + solve(nums, x, i, i + 1, dp);
        }
        exclude = solve(nums, x, prev, i + 1, dp);

        return dp[prev][i] = max(include, exclude);
    }

    long long tabulation(vector<int> &nums, int x)
    {
        // DP array
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        
        // base case 
        for (int i = 0; i < nums.size() + 1; i++)
        {
            dp[i][nums.size()] = 0;
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            for(int j = nums.size() - 1; j >= 1; j--){
                long long include = 0, exclude = 0;

                // parity check
                if (nums[i] % 2 == nums[j] % 2)
                {
                    include = nums[j] + dp[j][j + 1];
                }
                else
                {
                    include = nums[j] - x + dp[j][j + 1];
                }
                exclude = dp[i][j + 1];

                dp[i][j] = max(include, exclude);
            }
        }

        return dp[0][1];
    }

    long long maxScore(vector<int> &nums, int x)
    {
        // DP array
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return nums[0] + solve(nums, x, 0, 1, dp);
    }
};
