#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int max_len = 0;

        for (int rem = 0; rem < k; rem++)
        {
            vector<int> dp(n, 1);
            for (int i = 0; i < n; i++)
            {
                for (int prev = 0; prev < i; prev++)
                {
                    if ((nums[prev] + nums[i]) % k == rem)
                    {
                        dp[i] = max(dp[i], dp[prev] + 1);
                    }
                }
            }

            max_len = max(max_len, *max_element(dp.begin(), dp.end()));
        }

        return max_len;
    }
};
