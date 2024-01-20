#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int index, int len)
    {
        if (index == nums1.size())
        {
            return len;
        }

        int ans = INT_MIN;

        // include from nums1
        ans = max(ans, solve(nums1, nums2, index + 1, len + 1));

        // include from nums2
        

        return ans;
    }
    int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() == 1)
        {
            return 1;
        }

        return solve(nums1, nums2, 0, 1);
    }
};
