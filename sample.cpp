#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int ans = 0, l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (n - mid >= citations[mid])
            {
                if (citations[mid] > ans)
                {
                    ans = citations[mid];
                }
                l = mid + 1;
            }
            else
            {
                if (citations[mid] >= n - mid && n - mid > ans)
                {
                    ans = n - mid;
                }
                h = mid - 1;
            }
        }
        return ans;
    }
};
