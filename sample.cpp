#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo)
    {

        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = 1;
        }

        for (int i = 0; i < moveFrom.size(); i++)
        {
            mp[moveFrom[i]] = 0;
            mp[moveTo[i]] = 1;
        }

        vector<int> ans;

        for (auto it : mp)
        {
            if (it.second == 1)
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};
