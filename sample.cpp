#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> nums)
    {
        int n = nums.size();
        if(n<=2) return 0;
        int ans = 0;
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                {
                    mp[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> v = mp[i];
            for (int j = 0; j < v.size(); j++)
            {
                ans = ans + mp[v[j]].size();
            }
        }

        return ans;
    }
};
