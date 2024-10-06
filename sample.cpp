#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp(32, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                if ((1 << j) & nums[i])
                {
                    temp[j]++;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < 32; j++)
        {
            if(temp[j] % 3 != 0)
            {
                ans += (1 << j);
            }
        }
        return ans;
    }
};
