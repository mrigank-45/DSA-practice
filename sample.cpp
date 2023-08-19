#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Memoiation Solution
    int solve(int i, int total, pair<int, int> p, vector<int> arr, int ans, vector<vector<int>> dp)
    {
        // base case
        if (p.first == arr.size() / 2)
        {
            return min(ans, abs((total - p.second) - p.second));
        }
        if (i == arr.size())
        {
            return INT_MAX;
        }

        if (dp[i][p.first] != -1)
        {
            return dp[i][p.first];
        }

        int take = min(solve(i + 1, total, {p.first + 1, p.second + arr[i]}, arr, ans, dp), ans);
        int notTake = min(solve(i + 1, total, {p.first, p.second}, arr, ans, dp), ans);

        return dp[i][p.first] = min(take, notTake);
    }

    // tabulation
    int solve1(vector<int> arr)
    {
        int total = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        if (n == 1)
        {
            return arr[0];
        }

        vector<vector<int>> dp(n, vector<int>(n / 2 + 1, -1));

    }

    int minimumDifference(vector<int> &nums)
    {
        int total = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        if (n == 1)
        {
            return nums[0];
        }
        vector<vector<int>> dp(n, vector<int>(n / 2 + 1, -1));
        return solve(0, total, {0, 0}, nums, INT_MAX, dp);
    }
};
