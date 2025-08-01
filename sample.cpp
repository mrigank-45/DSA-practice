#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLargestOutlier(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mp[nums[i]] = i;
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = sum - nums[i];
            if (temp % 2 == 0 && mp.find(temp / 2) != mp.end() && mp[temp / 2] != i)
            {
                maxi = max(maxi, nums[i]);
            }
        }
        return maxi;
    }
};
