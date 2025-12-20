#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &nums, int n, int i, vector<int> &dp)
    {
        if(i>=n-1) return false;
        if (i == n - 2)
        {
            if (nums[i] == nums[i + 1])
                return true;
            return false;
        }
        if (i == n - 3)
        {
            bool c1 = (nums[i] == nums[i + 1]) && (nums[i + 1] == nums[i + 2]);
            bool c2 = (nums[i] + 1 == nums[i + 1]) && (nums[i + 1] + 1 == nums[i + 2]);
            if (c1 || c2)
                return true;
            return false;
        }
        if(dp[i] != -1) return dp[i];
        bool c1 = false, c2 = false;

        if(nums[i] == nums[i + 1]){
            c1 = solve(nums,n,i+2, dp);
        }

        if(((nums[i] == nums[i + 1]) && (nums[i + 1] == nums[i + 2]))|| ((nums[i] + 1 == nums[i + 1]) && (nums[i + 1] + 1 == nums[i + 2]))){
            c2 = solve(nums,n,i+3, dp);
        }
        return dp[i] = c1 || c2;
    }
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(nums, n, 0, dp);
    }
};
