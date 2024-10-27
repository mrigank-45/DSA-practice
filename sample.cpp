#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        int n = nums.size();

        unordered_map<int, pair<int, int>> mp; // {rem,{cnt,smallest element with this rem}}

        for (int i = 0; i < n; i++)
        {
            int rem = nums[i] % space;

            if (mp.find(rem) == mp.end())
            {
                mp[rem] = {1, nums[i]};
            }
            else
            {
                mp[rem].first++;
                mp[rem].second = min(mp[rem].second, nums[i]);
            }
        }

        int max_cnt = 0, smallest_element = INT_MAX;

        for (auto it : mp)
        {
            if (it.second.first > max_cnt)
            {
                max_cnt = it.second.first;
                smallest_element = it.second.second;
            }
            else if (it.second.first == max_cnt)
            {
                smallest_element = min(smallest_element, it.second.second);
            }
        }

        return smallest_element;
    }
};
