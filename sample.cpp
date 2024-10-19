#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 2)
            {
                ans[i] = -1;
            }
            else
            {
                int bit = 31;
                for (int j = 1; j < 32; j++)
                {
                    if (!(nums[i] & (1 << j)))
                    {
                        bit = j - 1;
                        break;
                    }
                }
                ans[i] = nums[i] ^ (1 << bit);
            }
        }

        return ans;
    }
};
