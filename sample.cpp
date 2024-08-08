#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int n, int i, int left)
    {
        int diff = nums2[0] - nums1[i];
        i++;
        int j = 1;
        while (j < nums2.size() && i < n)
        {
            if (nums2[j] - nums1[i] == diff)
            {
                j++;
                i++;
            }
            else
            {
                if (left == 0)
                    return INT_MAX;
                left--;
                i++;
            }
        }
        return diff;
    }
    int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = INT_MAX;
        ans = min(ans, solve(nums1, nums2, n, 0, 2));

        ans = min(ans, solve(nums1, nums2, n, 1, 1));

        ans = min(ans, solve(nums1, nums2, n, 2, 0));

        return ans;
    }
};
