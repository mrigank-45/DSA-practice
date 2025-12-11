#include <bits/stdc++.h>
using namespace std;

// Constraints:
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// 1 <= target <= 1000

class Solution
{
public:
    int dp[1005][1005];
    int fun(vector<int> &arr, int t, int i)
    {
        if (t == 0)
            return 0;
        if (i >= arr.size())
            return -1 * 1e5;

        if (dp[i][t] != -1)
            return dp[i][t];

        if (t >= arr[i])
            return dp[i][t] = max(1 + fun(arr, t - arr[i], i + 1), fun(arr, t, i + 1));

        return dp[i][t] = fun(arr, t, i + 1);
    }
    int lengthOfLongestSubsequence(vector<int> &arr, int t)
    {

        memset(dp, -1, sizeof(dp));
        int ans = fun(arr, t, 0);
        return ans < 0 ? -1 : ans;
    }
};
