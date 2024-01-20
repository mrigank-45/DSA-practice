#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() == 1)
        {
            return 1;
        }
        int ans = 0;
        int ele = min(nums1[0], nums2[0]);
        int temp = 1;
        for (int i = 1; i < nums1.size(); i++)
        {
            if (max(nums1[i], nums2[i]) < ele)
            {
                ans = max(ans, temp);
                temp = 1;
                ele = min(nums1[i], nums2[i]);
            }
            else if (nums1[i] <= nums2[i])
            {
                if (nums1[i] >= ele)
                {
                    temp++;
                    ele = nums1[i];
                }
                else
                {
                    temp++;
                    ele = nums2[i];
                }
            }
            else if (nums2[i] <= nums1[i])
            {
                if (nums2[i] >= ele)
                {
                    temp++;
                    ele = nums2[i];
                }
                else
                {
                    temp++;
                    ele = nums1[i];
                }
            }

            if (i < nums1.size() - 1 && max(nums1[i + 1], nums2[i + 1]) < ele)
            {
                ans = max(ans, temp);
                temp = 1;
                ele = min(nums1[i], nums2[i]);
            }

            if (i == nums1.size() - 1)
            {
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};
