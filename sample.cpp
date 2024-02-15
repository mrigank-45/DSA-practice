#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKOr(vector<int> &nums, int k)
    {
        int n = nums.size();

        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                int temp = nums[i];
                temp = temp >> j;
                int bit = temp & 1;
                if (bit == 1)
                {
                    mp[j]++;
                }
            }
        }

        unsigned int bitmask = 1;

        bool flag = 0;

        for (int j = 0; j < 32; j++)
        {
            if (mp[j] >= k)
            {
                flag = 1;
                bitmask = bitmask | (1 << j);
            }
        }

        if(flag == 0)
        {
            return 0;
        }

        return bitmask;
    }
};
