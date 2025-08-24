#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        int ans = 0, i = 0, sum = 0;
        mp[0] = 1;
        while (i < n)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem == 0 && i != 0)
                ans++;

            ans += mp[rem];
            if ((sum - nums[i]) % k == rem)
                ans--;
            mp[rem]++;
            i++;
        }
        return ans;
    }
};
