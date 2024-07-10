#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, int score, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if (nums[i] + nums[j] == score)
        {
            ans = max(ans, 1 + solve(i + 1, j - 1, score, nums, dp));
        }
        if (nums[i] + nums[i + 1] == score)
        {
            ans = max(ans, 1 + solve(i + 2, j, score, nums, dp));
        }
        if (nums[j] + nums[j - 1] == score)
        {
            ans = max(ans, 1 + solve(i, j - 2, score, nums, dp));
        }

        return dp[i][j] = ans;

    }
    int maxOperations(vector<int> &nums)
    {
        int n = nums.size();
        
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != nums[0])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return n / 2;
        }
        int size = max(nums[0] + nums[1],max(nums[0] + nums[n - 1], nums[n - 1] + nums[n - 2]));


        int ans = 0;

        vector<vector<int>> dp1(n + 1, vector<int>(n + 1, -1));
        ans = max(ans, 1 + solve(1, n - 2, nums[0] + nums[n - 1], nums, dp1));

        vector<vector<int>> dp2(n + 1, vector<int>(n + 1, -1));
        ans = max(ans, 1 + solve(2, n - 1, nums[0] + nums[1], nums, dp2));

        vector<vector<int>> dp3(n + 1, vector<int>(n + 1, -1));
        ans = max(ans, 1 + solve(0, n - 3, nums[n - 1] + nums[n - 2], nums, dp3));

        return ans;
    }
};
