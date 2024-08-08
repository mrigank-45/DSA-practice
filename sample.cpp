#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long helper(vector<int> &nums, int mid, int n)
    {
        long long ans = 0;
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        while (j < n)
        {
            mp[nums[j]]++;
            while (i <= j && mp.size() > mid)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int medianOfUniquenessArray(vector<int> &nums)
    {
        int n = nums.size();
        long long m;
        if (n % 2 == 0)
        {
            m = (long long)(n / 2) * (long long)(n - 1) + (long long)n;
        }
        else
        {
            m = (long long)((n - 1) / 2) * (long long)(n) + (long long)n;
        }

        int s = 1, e = n;

        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (helper(nums, mid, n) == (m + 1) / 2)
            {
                ans = mid;
                break;
            }
            else if (helper(nums, mid, n) > (m + 1) / 2)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};
