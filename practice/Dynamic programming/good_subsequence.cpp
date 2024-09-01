// Find the Maximum Length of a Good Subsequence II
// instead of storing prev element to check if the current element is same as prev element, we are using a bool with help of a map to store the indexes of the same element

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[5001][2][51];
    int solve(int i, int count, bool same, vector<int> &nums, unordered_map<int, vector<int>> &mp)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i][same][count] != -1)
            return dp[i][same][count];

        int take = 0, notake = 0;
        vector<int> &v = mp[nums[i]];
        int ind = upper_bound(v.begin(), v.end(), i) - v.begin();

        if (ind == v.size())
            take = 1;
        else
            take = 1 + solve(v[ind], count, true, nums, mp);

        if (count > 0)
            take = max(take, 1 + solve(i + 1, count - 1, false, nums, mp));
        if (same == false)
            notake = solve(i + 1, count, false, nums, mp);

        return dp[i][same][count] = max(take, notake);
    }

    int maximumLength(vector<int> &nums, int k)
    {
        memset(dp, -1, sizeof(dp));
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }

        return solve(0, k, false, nums, mp);
    }
};
