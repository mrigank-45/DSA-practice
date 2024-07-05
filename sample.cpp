#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long ans = LONG_MIN;
        int n = nums.size();
        vector<long long> preSum(n, nums[0]);
        for (int i = 1; i < n; i++)
        {
            preSum[i] = preSum[i - 1] + nums[i];
        }

        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            int val1 = nums[i] - k;
            int val2 = nums[i] + k;

            if (mp.find(val1) != mp.end())
            {
                for (auto idx : mp[val1])
                {
                    ans = max(ans, i < idx ? preSum[idx] - preSum[i] + nums[i] : preSum[i] - preSum[idx] + nums[idx]);
                }
            }
            if (mp.find(val2) != mp.end())
            {
                for (auto idx : mp[val1])
                {
                    ans = max(ans, i < idx ? preSum[idx] - preSum[i] + nums[i] : preSum[i] - preSum[idx] + nums[idx]);
                }
            }
        }
        return ans == LONG_MIN ? 0 : ans;
    }
};
