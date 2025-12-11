// Find the Sum of Subsequence Powers

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int i, int last, int k, int minDiff, vector<int> &nums, vector<vector<vector<unordered_map<int, int>>>> &memo, int n)
    {
        if (k == 0)
        {
            return minDiff;
        }
        if (i == n)
            return 0;
        if (memo[i][last][k].count(minDiff))
        {
            return memo[i][last][k][minDiff];
        }

        // Pick
        int diff = last == n ? INT_MAX : nums[i] - nums[last];
        int ans = solve(i + 1, i, k - 1, min(minDiff, diff), nums, memo, n);
        // Not pick
        ans = (ans + solve(i + 1, last, k, minDiff, nums, memo, n)) % mod;

        return memo[i][last][k][minDiff] = ans;
    }
    int sumOfPowers(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<vector<unordered_map<int, int>>>> memo(n, vector<vector<unordered_map<int, int>>>(n + 1, vector<unordered_map<int, int>>(k + 1)));

        return solve(0, n, k, INT_MAX, nums, memo, n);
    }
};
