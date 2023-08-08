// Longest Arithmetic Subsequence (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion
    int solve(int index, int diff, vector<int> &nums)
    {
        if (index < 0)
        {
            return 0;
        }
        int ans = 0;
        for (int j = index - 1; j >= 0; j--)
        {
            if (nums[index] - nums[j] == diff)
            {
                ans = max(ans, 1 + solve(j, diff, nums));
            }
        }
        return ans;
    }

    // recursion + memo
    int solve1(int index, int diff, vector<int> &nums, unordered_map<int, int> dp[])
    {
        if (index < 0)
        {
            return 0;
        }
        if (dp[index].count(diff))
        {
            return dp[index][diff];
        }
        int ans = 0;
        for (int j = index - 1; j >= 0; j--)
        {
            if (nums[index] - nums[j] == diff)
            {
                ans = max(ans, 1 + solve1(j, diff, nums, dp));
            }
        }
        return dp[index][diff] = ans;
    }

    // tabulation
    int solve2(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }
        unordered_map<int, int> dp[n + 1];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                int count = 1;
                if (dp[j].count(diff))
                {
                    count = dp[j][diff];
                }
                dp[i][diff] = 1 + count;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }

    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> dp[n + 1];
        if (n <= 2)
        {
            return n;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // recursion
                // ans=max(ans,2+solve(i,nums[j]-nums[i],nums));

                ans = max(ans, 2 + solve1(i, nums[j] - nums[i], nums, dp));
            }
        }
        return ans;
    }
};
