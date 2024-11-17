#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long count = 0;

        for(int i = 0; i < n; i++)
        {
            int l = lower - nums[i];
            int u = upper - nums[i];

            int a = lower_bound(nums.begin(), nums.end(), l) - nums.begin();

            int b = upper_bound(nums.begin(), nums.end(), u) - nums.begin() - 1;

            if(a==n || b==-1 || a > b)
            {
                continue;
            }

            count += b - a + 1;

        }

        return count;
    }
};
