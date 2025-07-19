#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<vector<int>> ans;
    void solve(vector<int> nums, int n, int i, vector<int> output)
    {
        if (output.size() > 1)
            ans.insert(output);
        if (i == n)
            return;

        // not choose
        solve(nums, n, i + 1, output);

        // choose
        if (output.size() == 0 || nums[i] >= output.back())
        {
            output.push_back(nums[i]);
            solve(nums, n, i + 1, output);
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output;
        solve(nums, n, 0, output);
        vector<vector<int>> res;
        for (auto it : ans)
        {
            res.push_back(it);
        }
        return res;
    }
};
