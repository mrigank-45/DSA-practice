#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        int ans = 0;
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                ans += (it.second + 2) / 3;
            }
            else
            {
                return -1;
            }
        }
    }
};
