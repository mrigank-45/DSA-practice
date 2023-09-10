#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(int curr, int prev, vector<int> &nums)
    {
        if (curr == nums.size())
        {
            return {};
        }

        vector<int> take({});
        vector<int> notTake = solve(curr + 1, prev, nums);
        if (prev == -1 || (nums[curr] % nums[prev] == 0 || nums[prev] % nums[curr] == 0))
        {
            take = solve(curr + 1, curr, nums);
            take.insert(take.begin(), nums[curr]);
        }
        if(take.size() > notTake.size())
        {
            return take;
        }
        return notTake;
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));

        return solve(0, -1, nums);
    }
};
