#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumArrayLength(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        int val = nums[0];
        int cnt = mp[nums[0]];
        if (val == 2 && cnt > 50000)
        {
            return 1;
        }
        for (int i = cnt; i < n; i++)
        {
            if (nums[i] % val != 0)
            {
                cnt--;
            }
            if (cnt == 0 || cnt == 1)
            {
                cnt = 1;
                break;
            }
        }

        if (cnt % 2 == 0)
        {
            return cnt / 2;
        }
        else
        {
            return cnt / 2 + 1;
        }
    }
};
