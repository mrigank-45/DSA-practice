#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int i, int n, vector<long long> &diff, vector<long long> &dp)
    {
        if (i > n - 3)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        long long take = 1e18;

        for (int c = i; c < n && c < i + 3; c++)
        {

            long long temp = (diff[c] + solve(c + 1, n, diff, dp));

            take = min(take, temp);
        }

        return dp[i] = take;
    }

    long long minIncrementOperations(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return 0;
        }

        int n = nums.size();

        vector<long long> diff;  // precompute the differnce of each element with k

        for (auto i : nums)
        {
            if (i < k)
            {
                diff.push_back(k - i);
            }
            else
            {
                diff.push_back(0);
            }
        }

        vector<long long> dp(n, -1);

        return solve(0, n, diff, dp);
    }
};
