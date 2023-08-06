// Longest Increasing Subsequence (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion + memorisation
    int solve(int curr, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (curr == nums.size())
            return 0;

        // doing prev + 1 becs we have initialised prev with -1
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        int take = 0;
        int notTake = solve(curr + 1, prev, nums, dp);
        if (prev == -1 || nums[curr] < nums[prev])
        {
            take = 1 + solve(curr + 1, curr, nums, dp);
        }
        dp[curr][prev + 1] = max(take, notTake);
        return dp[curr][prev + 1];
    }

    // tabulation
    int solve1(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int notTake = 0 + dp[curr + 1][prev + 1];
                int take = 0;

                if (prev == -1 || nums[curr] > nums[prev])
                    take = 1 + dp[curr + 1][curr + 1];

                dp[curr][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }

    // space optamization
    int solve2(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int notTake = 0 + nextRow[prev + 1];
                int take = 0;

                if (prev == -1 || nums[curr] > nums[prev])
                    take = 1 + nextRow[curr + 1];

                currRow[prev + 1] = max(take, notTake);
                nextRow = currRow;
            }
        }

        return nextRow[0];
    }

    // TC: O(nlogn), previosely it was O(n2)
    // using binary search
    int solveOptimal(int n, vector<int> &nums)
    {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(nums[0]);
        
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                // find the index that is just bigger in ans vector
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return solve(0, -1, nums, dp);
    }
};
