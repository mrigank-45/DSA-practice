#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int i, int last, int n, const vector<int> &nums, unordered_map<string, int> &dp)
    {
        if (i >= n)
            return 0;

        string key = to_string(last) + "-" + to_string(i);
        if (dp.find(key) != dp.end())
            return dp[key];

        if (nums[i] < last)
            return dfs(i + 1, last, n, nums, dp);
        int take = 0;

        if (nums[i] == last)
            take = max(1 + dfs(i + 1, nums[i] + 1, n, nums, dp), take);
        if (nums[i] == last + 1)
            take = max(1 + dfs(i + 1, nums[i], n, nums, dp), take);

        dp[key] = take;
        return take;
    }

    int maxSelectedElements(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<string, int> dp;

        int res = 1;
        for (int i = 0; i < n; i++)
        {
            res = max(res, max(dfs(i + 1, nums[i], n, nums, dp) + 1, dfs(i + 1, nums[i] + 1, n, nums, dp) + 1));
        }

        return res;
    }
};
