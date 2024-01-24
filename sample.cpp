#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfGoodSubarraySplits(vector<int> &nums)
    {
        int mod = (int)(1e9 + 7);

        vector<int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                temp.push_back(i);
            }
        }

        int ans = 1;

        if (temp.size() == 0)
        {
            return 0;
        }

        if (temp.size() == 1)
        {
            return 1;
        }

        for (int i = 1; i < temp.size(); i++)
        {
            ans = (ans * (temp[i] - temp[i - 1]) % mod) % mod;
        }
        return ans % mod;
    }
};
