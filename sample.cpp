#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int i, vector<int> &nums, vector<int> &v, int n)
    {
        if (i == n)
        {
            for (int j = 1; j < v.size(); j++)
            {
                if (v[j] != v[j - 1])
                {
                    return false;
                }
            }
            return true;
        }

        for (int j = 0; j < v.size(); j++)
        {
            v[j] += nums[i];
            if (solve(i+1, nums, v, n))
            {
                return true;
            }
            v[j] -= nums[i];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        if (k == 1)
            return true;
        int n = nums.size();
        vector<int> v(k, 0);
        return solve(0, nums, v, n);
    }
};
