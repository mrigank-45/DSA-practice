#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        int i = 0, j = 0;
        int zeroCount = 0;

        while(j < n)
        {
            if(nums[j] == 0)
            {
                zeroCount++;
            }

            while(zeroCount > 1)
            {
                if(nums[i] == 0)
                {
                    zeroCount--;
                }
                i++;
            }

            ans = max(ans, j - i);
            j++;
        }

        return ans;
    }
};
