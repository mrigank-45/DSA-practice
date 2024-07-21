#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const long long INF = -1e9; // Use the smallest value for invalid results

    long long maxStrength(vector<int> &nums, int i, int k, bool isStarting, long long currentSum, vector<vector<vector<long long>>> &memo)
    {
        if (k == 0)
        {
            return 0; // No more subarrays needed
        }
        if (i >= nums.size())
            return INF; // Reached end of array

        int state = isStarting ? 0 : 1;
        if (memo[i][k][state] != -1)
            return memo[i][k][state]; // Return memoized result

        long long result = INF;
        if (isStarting)
        {
            // Choice 1: Start a new subarray at index i
            result = max(result, maxStrength(nums, i + 1, k, false, nums[i], memo));
            // Choice 2: Skip the current element
            result = max(result, maxStrength(nums, i + 1, k, true, 0, memo));
            // Choice 3: start and end the current subarray at index i
            int sign = (k % 2 == 1) ? 1 : -1; // Positive if k is odd, negative if k is even
            result = max(result, sign * (nums[i]) * k + maxStrength(nums, i + 1, k - 1, true, 0, memo));
        }
        else
        {
            // Choice 1: Continue the current subarray
            result = max(result, maxStrength(nums, i + 1, k, false, currentSum + nums[i], memo));
            // Choice 2: End the current subarray at index i
            int sign = (k % 2 == 1) ? 1 : -1; // Positive if k is odd, negative if k is even
            result = max(result, sign * (currentSum + nums[i]) * k + maxStrength(nums, i + 1, k - 1, true, 0, memo));
        }

        memo[i][k][state] = result; // Memoize the result
        return result;
    }

    long long maximumStrength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(k + 1, vector<long long>(2, -1))); // 3D DP array
        return maxStrength(nums, 0, k, true, 0, memo);
    }
};
