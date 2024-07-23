// Find the Sum of the Power of All Subsequences
#include <bits/stdc++.h>
using namespace std;

// If there's a subsequence of length l with sum k, it will contribute 2^(n-l) to the answer.
// reason: this length l can be combined with any of the remaining n-l elements to form a subsequence with sum k.

class Solution
{
public:
    int mod = 1e9 + 7, n;
    int dp[101][101][101];

    // calculate 2^x
    int func(int x)
    {
        int ans = 1;
        while (x--)
            ans = (ans * 2) % mod;
        return ans;
    }
    int helper(int ind, vector<int> &nums, int curr_sum, int len, int k)
    {
        if (curr_sum > k)
            return 0;
        if (curr_sum == k)
            return func(n - len);
        if (ind == n)
            return 0;
        if (dp[ind][curr_sum][len] != -1)
            return dp[ind][curr_sum][len];
        int cnt = 0;
        cnt = (cnt + helper(ind + 1, nums, curr_sum + nums[ind], len + 1, k)) % mod;
        cnt = (cnt + helper(ind + 1, nums, curr_sum, len, k)) % mod;
        return dp[ind][curr_sum][len] = cnt;
    }

    int sumOfPower(vector<int> &nums, int k)
    {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, nums, 0, 0, k);
    }
};
