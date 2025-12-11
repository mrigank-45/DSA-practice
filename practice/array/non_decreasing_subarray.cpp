#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), pre1 = 1, pre2 = 1, n1 = 1, n2 = 1, ans = 1;
        for (int i = 1; i < n; i++)
        {
            n1 = 1;
            n2 = 1;
            if (nums1[i] >= nums1[i - 1])
            {
                n1 = pre1 + 1;
            }
            if (nums1[i] >= nums2[i - 1])
            {
                n1 = max(n1, pre2 + 1);
            }

            if (nums2[i] >= nums2[i - 1])
            {
                n2 = pre2 + 1;
            }
            if (nums2[i] >= nums1[i - 1])
            {
                n2 = max(n2, pre1 + 1);
            }
            ans = max(ans, max(n1, n2));
            pre1 = n1;
            pre2 = n2;
        }
        return ans;
    }
};
