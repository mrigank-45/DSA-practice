#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int op1, int op2, int k, vector<int> nums, int n, vector<vector<vector<int>>> &dp)
    {
        if ((op1 == 0 && op2 == 0) || i == n)
        {
            return 0;
        }

        if (dp[i][op1][op2] != -1)
        {
            return dp[i][op1][op2];
        }

        int ans = 0;
        if (op1 > 0)
        {
            int temp = (nums[i] / 2);

            ans = max(ans, temp + solve(i + 1, op1 - 1, op2, k, nums, n, dp));
        }
        if (op2 > 0 && nums[i] >= k)
        {
            int temp = k;

            ans = max(ans, temp + solve(i + 1, op1, op2 - 1, k, nums, n, dp));
        }
        if (op1 > 0 && op2 > 0 && nums[i] > 1)
        {
            int temp = (nums[i] / 2);
            if ((nums[i] / 2) + (nums[i] % 2 == 1) >= k)
            {
                temp += k;
            }
            ans = max(ans, temp + solve(i + 1, op1 - 1, op2 - 1, k, nums, n, dp));
        }
        if (op1 > 0 && op2 > 0 && nums[i] >= k)
        {
            int temp = k;
            if ((nums[i] - k) > 1)
            {
                temp += ((nums[i] - k) / 2);
            }
            ans = max(ans, temp + solve(i + 1, op1 - 1, op2 - 1, k, nums, n, dp));
        }

        ans = max(ans, solve(i + 1, op1, op2, k, nums, n, dp));

        return dp[i][op1][op2] = ans;
    }
    int minArraySum(vector<int> &nums, int k, int op1, int op2)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        int maxi = solve(0, op1, op2, k, nums, n, dp);
        return sum - maxi;
    }
};
