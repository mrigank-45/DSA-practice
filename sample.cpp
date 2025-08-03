#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> mp;
    int solve(int i, vector<int> &nums)
    {
        if (nums[i] == -1)
        {
            return 0;
        }
        int index = nums[i];
        nums[i] = -1; 
        mp[i] = 1 + solve(index, nums);

        return mp[i];
    }

    int arrayNesting(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if(mp.find(i) == mp.end())
            {
                solve(i, nums);
            }
        }
        int ans = 0;
        for (auto &it : mp)
        {
            ans = max(ans, it.second);
        }
        return ans;
    }
};
