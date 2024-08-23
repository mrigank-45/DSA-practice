#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumNonAdjacent(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return max(0, nums[0]);

        int prev1 = max(0, nums[0]);
        int prev2 = 0;
        int maxSum = prev1;

        for (int i = 1; i < n; ++i)
        {
            maxSum = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = maxSum;
        }

        return maxSum;
    }

    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries)
    {
        const int MOD = 1e9 + 7;
        long long totalSum = 0;

        for (auto &query : queries)
        {
            int pos = query[0];
            int newValue = query[1];
            nums[pos] = newValue;
            totalSum = (totalSum + maxSumNonAdjacent(nums)) % MOD;
        }

        return totalSum;
    }
};
