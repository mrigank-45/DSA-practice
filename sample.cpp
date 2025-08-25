#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prefix;
    vector<vector<double>> dp;

    double solve(int i, int k, vector<int> &nums)
    {
        int n = nums.size();
        if (k == 1)
        {
            return (prefix[n] - prefix[i]) * 1.0 / (n - i);
        }

        if (dp[i][k] >= 0)
            return dp[i][k];

        double ans = 0;
        for (int j = i + 1; j <= n - k + 1; j++)
        {
            double avg = (prefix[j] - prefix[i]) * 1.0 / (j - i);
            ans = max(ans, avg + solve(j, k - 1, nums));
        }

        return dp[i][k] = ans;
    }

    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        
        dp.assign(n, vector<double>(k + 1, -1));
        
        return solve(0, k, nums);
    }
};
