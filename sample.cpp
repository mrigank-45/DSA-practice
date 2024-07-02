#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0;
        int len = 1;
        pair<int, int> res = {0, 0};

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                if (i == n - 1)
                {
                    if (i - start + 1 >= len)
                    {
                        res = {start, i};
                    }
                }
                continue;
            }
            else
            {
                if (i - start > len)
                {
                    res = {start, i - 1};
                    len = i - start;
                    cout<<i<<endl;
                    cout << res.first << " " << res.second << endl;
                }
                start = i;
            }
        }
        int sum = 0;

        for (int i = res.first; i <= res.second; i++)
        {
            sum += nums[i];
        }

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int ans = sum;
        while (1)
        {
            if (mp.find(ans) == mp.end())
            {
                return ans;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};
