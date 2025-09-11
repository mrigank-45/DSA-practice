#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        reverse(nums2.begin(), nums2.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int val = nums1[i];
            int index = lower_bound(nums2.begin(), nums2.end(), val) - nums2.begin();
            index = m - 1 - index;
            if (index != m)
            {
                ans = max(ans, index - i);
            }
        }
        return ans;
    }
};
