#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int ans = 1;
        for (auto it : mp)
        {
            if (it.second < 2 || it.first == 1)
            {
                continue;
            }
            else
            {
                int cnt = 2;
                int k = 2;
                while (1)
                {
                    if (pow(it.first, k) <= INT_MAX && mp[pow(it.first, k)] > 1)
                    {
                        cnt += 2;
                        k = k + k;
                    }
                    else if (pow(it.first, k) <= INT_MAX && mp[pow(it.first, k)] == 1)
                    {
                        cnt++;
                        break;
                    }
                    else
                    {
                        cnt--;
                        break;
                    }
                }
                ans = max(ans, cnt);
            }
        }
        if (mp[1] % 2 == 0)
        {
            ans = max(ans, mp[1] - 1);
        }
        else
        {
            ans = max(ans, mp[1]);
        }
        return ans;
    }
};
