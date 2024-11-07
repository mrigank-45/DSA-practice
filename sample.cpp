#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[position[i]] = speed[i];
        }

        sort(position.begin(), position.end());

        int ans = n, flag = 0;

        for(int i = n - 1; i > 0; i--)
        {
            double time1 = (double)(target - position[i]) / mp[position[i]];
            double time2 = (double)(target - position[i - 1]) / mp[position[i - 1]];

            if(time1 >= time2)
            {
                mp[position[i - 1]] = mp[position[i]];
                ans--;
            }
        }

        return ans;
    }
};
