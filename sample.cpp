#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                {
                    ans = max(ans, nums[i] ^ nums[j]);
                }
            }
        }
        return ans;
    }
};
