// Minimum Swaps To Make Sequences Increasing (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, vector<int> &nums1, vector<int> &nums2, bool swapped)
    {
        int n = nums1.size();
        // base case
        if (index == n)
            return 0;

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped) // we swapped is true then we swap prev1 and prev2
            swap(prev1, prev2);

        // noswap
        if (prev1 < nums1[index] && prev2 < nums2[index])
        {
            ans = solve(index + 1, nums1, nums2, 0);
        }

        // swap
        if (prev1 < nums2[index] && prev2 < nums1[index])
        {
            ans = min(ans, 1 + solve(index + 1, nums1, nums2, 1));
        }
        return ans;
    }

    int solveMem(int index, vector<int> &nums1, vector<int> &nums2, bool swapped, vector<vector<int>> &dp)
    {
        int n = nums1.size();
        // base case
        if (index == n)
            return 0;

        if (dp[index][swapped] != -1)
            return dp[index][swapped];

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped) // swapped is true then we swap prev1 and prev2
            swap(prev1, prev2);

        // noswap
        if (prev1 < nums1[index] && prev2 < nums2[index])
        {
            ans = solveMem(index + 1, nums1, nums2, 0, dp);
        }

        // swap
        if (prev1 < nums2[index] && prev2 < nums1[index])
        {
            ans = min(ans, 1 + solveMem(index + 1, nums1, nums2, 1, dp));
        }
        return dp[index][swapped] = ans;
    }

    int solveTab(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped) // we swapped is true then we swap prev1 and prev2
                    swap(prev1, prev2);

                // noswap
                if (prev1 < nums1[index] && prev2 < nums2[index])
                {
                    ans = dp[index + 1][0];
                }

                // swap
                if (prev1 < nums2[index] && prev2 < nums1[index])
                {
                    ans = min(ans, 1 + dp[index + 1][1]);
                }
                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    int solveSO(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped) // we swapped is true then we swap prev1 and prev2
                    swap(prev1, prev2);

                // noswap
                if (prev1 < nums1[index] && prev2 < nums2[index])
                {
                    ans = next[0];
                }

                // swap
                if (prev1 < nums2[index] && prev2 < nums1[index])
                {
                    ans = min(ans, 1 + next[1]);
                }
                curr[swapped] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        bool swapped = 0;
        // return solve(1,nums1,nums2,swapped);

        // vector<vector<int>>  dp(n+1, vector<int>(2,-1));
        // return solveMem(1,nums1,nums2,swapped,dp);

        // return solveTab(nums1,nums2);

        return solveSO(nums1, nums2);
    }
};
