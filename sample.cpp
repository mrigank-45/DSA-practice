#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();

        int ans = 0;
        int l = 0, r = 0;

        long long int temp = nums[0];

        while (l < n)
        {
            if (l == n)
            {
                break;
            }
            if (temp < (long long int)k)
            {
                ans++;
                r++;
                if (r < n)
                {
                    temp = temp * nums[r];
                }

                if (r == n)
                {
                    l++;
                    r = l;
                    if (l < n)
                    {
                        temp = nums[l];
                    }
                    continue;
                }
            }
            else
            {
                l++;
                r = l;
                if (l < n)
                {
                    temp = nums[l];
                }
                continue;
            }
        }

        return ans;
    }
};
