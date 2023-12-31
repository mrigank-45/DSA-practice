#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAbsoluteDifference(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        set<int> s;
        int ans = INT_MAX, n = nums.size();
        for (int i = k; i < n; i++)
        {
            mp[nums[i]]++;
            s.insert(nums[i]);
        }
        for (int i = 0; i < n && !s.empty(); i++)
        {
            if (s.lower_bound(nums[i]) != s.end())
            {
                auto a = s.lower_bound(nums[i]);
                ans = min(ans, *a - nums[i]);
            }
            mp[nums[i + k]]--;
            if (mp[nums[i + k]] == 0)
            {
                mp.erase(nums[i + k]);
                s.erase(nums[i + k]);
            }
        }
        mp.clear();
        s.clear();
        reverse(nums.begin(), nums.end());
        for (int i = k; i < n; i++)
        {
            mp[nums[i]]++;
            s.insert(nums[i]);
        }
        for (int i = 0; i < n && !s.empty(); i++)
        {
            if (s.lower_bound(nums[i]) != s.end())
            {
                auto a = s.lower_bound(nums[i]);
                ans = min(ans, *a - nums[i]);
            }
            mp[nums[i + k]]--;
            if (mp[nums[i + k]] == 0)
            {
                mp.erase(nums[i + k]);
                s.erase(nums[i + k]);
            }
        }
        return ans;
    }
};
