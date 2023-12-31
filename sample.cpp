#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, int sum, vector<int> &v, vector<vector<int>> &dp, int m)
    {
        if (i >= j)
        {
            return true;
        }
        else if (j - i + 1 <= 2)
        {
            return true;
        }
        else if (sum < m)
        {
            return false;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans1 = false;
        if (sum - v[i] >= m)
        {
            ans1 |= solve(i + 1, j, sum - v[i], v, dp, m);
        }
        if (sum - v[j] >= m)
        {
            ans1 |= solve(i, j - 1, sum - v[j], v, dp, m);
        }
        

        return dp[i][j] = ans1;
    }
    bool canSplitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int sum = 0;
        for (auto &i : nums)
        {
            sum += i;
        }
        return solve(0, n - 1, sum, nums, dp, m);
    }
};
