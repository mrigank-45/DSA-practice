#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lis(vector<int> &nums, int n)
    {
        if (n == 0)
        {
            return 0;
        }

        vector<int> result;
        result.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > result.back())
            {
                result.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(result.begin(), result.end(), nums[i]) - result.begin();
                result[index] = nums[i];
            }
        }

        return result.size();
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // SORT THE VECTOR
        // {widht,height}, {a,b}, then a is sorted increasing order, b is sorted in decreasing order
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); });

        // apply longest increasing subsequence in second part (height)
        vector<int> nums;
        for (auto i : envelopes)
        {
            nums.push_back(i[1]);
        }

        int n = nums.size();
        return lis(nums, n);
    }
};
