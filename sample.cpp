#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &bloomDay, int m, int k, int mid)
    {
        int n = bloomDay.size();
        int flowers = 0;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
            {
                flowers++;
                if (flowers == k)
                {
                    res++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }

        if (res >= m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (m * k > bloomDay.size())
        {
            return -1;
        }
        int s = 0;
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        int mid = s + (e - s) / 2;
        int ans = e;

        while (s <= e)
        {
            if (possible(bloomDay, m, k, mid))
            {
                ans = min(ans, mid);
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }

        return ans;
    }
};
