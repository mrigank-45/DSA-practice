#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSetBits(int val)
    {
        int cnt = 0;
        while (val)
        {
            if (val & 1)
            {
                cnt++;
            }
            val = val >> 1;
        }
        return cnt;
    }
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = countSetBits(nums[i]);
        }
        int i = 0;
        while (i < n - 1)
        {
            if (nums[i] > nums[i + 1])
            {
                if (mp[nums[i]] != mp[nums[i + 1]])
                {
                    break;
                }
                while (i < n - 1 && nums[i] > nums[i + 1] && mp[nums[i]] == mp[nums[i + 1]])
                {
                    swap(nums[i], nums[i + 1]);
                    i++;
                }
                i = 0;
            }
            else
            {
                i++;
            }
        }
        if (is_sorted(nums.begin(), nums.end()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
