#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if(n < 3)
        {
            return 0;
        }
        int ans = 0;
        int diff = nums[1] - nums[0];
        int len = 2;

        for (int i = 1; i < n - 1; i++)
        {
            if(nums[i+1] - nums[i] == diff)
            {
                len++;
                if(i == n - 2)
                {
                    if(len >= 3)
                    {
                        ans += (len - 1) * (len - 2) / 2;
                    }
                }
            }
            else
            {
                if(len >= 3)
                {
                    ans += (len - 1) * (len - 2) / 2;
                }
                diff = nums[i+1] - nums[i];
                len = 2;
            }
        }

        return ans;
    }
};
