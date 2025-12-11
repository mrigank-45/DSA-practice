// Maximum sum of non-adjacent elements
// NOTE: in circular type input where first and last element are adjacent, return max of solution(2nd element to last) ans solution(1st element tpo second last).

#include <bits/stdc++.h>
using namespace std;

// recursion
int solve(vector<int> &nums, int index)
{
    // Base Case.
    if (index < 0)
    {
        return 0;
    }

    // Including the current element of the given array/list in our subsequence.
    int optionA = solve(nums, index - 2) + nums[index];

    // Excluding the current element of the given array/list from our subsequence.
    int optionB = solve(nums, index - 1);

    return max(optionA, optionB);
}

// recursion + memoization
// {easy}

// tabulation
int solve1(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
    {
        return 0;
    }

    // Array to store previous results.
    vector<int> dp(n + 1);

    // Base Cases.
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int optionA = dp[i - 2] + nums[i];
        int optionB = dp[i - 1] + 0;
        dp[i] = max(optionA, optionB);
    }
    return dp[n - 1];
}

// space optamization
int solve2(vector<int> &nums)
{
    int n = nums.size();

    // Two variables to store the previous results.
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 0; i < n; i++)
    {
        int optionA = prev2 + nums[i];
        int optionB = prev1 + 0; 
        int ans = max(optionA, optionB);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

// main function
int maximumNonAdjacentSum(vector<int> &nums)
{
    // int n = nums.size();
    // return solve(nums, n - 1);

    return solve1(nums);

    return solve2(nums);
}
