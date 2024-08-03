// Minimum Sum of Values by Dividing Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int m;

    vector<vector<unordered_map<int, int>>> dp;
    int solve(vector<int> &nums, vector<int> &andValues, int i, int j, int andOp)
    {
        // base case
        if (i >= n)
        {
            if (j >= m)
                return 0;
            else
                return 1e9;
        }
        else if (j >= m)
        {
            return 1e9;
        }

        // recursive call
        if (dp[i][j].count(andOp))
        {
            return dp[i][j][andOp];
        }
        int take_i = 1e9;

        if ((andOp & nums[i]) == andValues[j])
        {
            take_i = nums[i] + solve(nums, andValues, i + 1, j + 1, ((1 << 17) - 1));
        }
        int not_take_i = solve(nums, andValues, i + 1, j, andOp & nums[i]);

        return dp[i][j][andOp] = min(take_i, not_take_i);
    }
    int minimumValueSum(vector<int> &nums, vector<int> &andValues)
    {
        n = nums.size();
        m = andValues.size();

        dp.resize(n + 1, vector<unordered_map<int, int>>(11));
        // {index,number of subarrays done, andOp}
        int result = solve(nums, andValues, 0, 0, ((1 << 17) - 1));

        return result == 1e9 ? -1 : result;
    }
};
