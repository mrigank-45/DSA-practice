#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(32, 0);

        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[j] & (1 << i))
                {
                    v[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans += v[i] * (n - v[i]);
        }
        return ans;
    }
};
