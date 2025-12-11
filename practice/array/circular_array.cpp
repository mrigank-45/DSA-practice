// Minimum Seconds to Equalize a Circular Array (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSeconds(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }

        int ans = nums.size(), x = 0;

        for (auto &it : mp)
        {
            x = it.second[0];
            int y = nums.size() - it.second.back() - 1;
            x = x + y;
            x = (x + 1) / 2;

            for (int i = 0; i < it.second.size() - 1; i++)
            {
                x = max(x, (it.second[i + 1] - it.second[i]) / 2);
            }
            ans = min(ans, x);
        }
        return ans;
    }
};
