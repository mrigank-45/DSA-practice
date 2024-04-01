#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long int val1 = 0, val2 = 0, flag1 = 0, flag2 = 0;

        for (long long int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == 0)
            {
                val1++;
                flag1 = 1;
            }
            else
            {
                val1 = val1 + nums1[i];
            }
        }

        for (long long int i = 0; i < nums2.size(); i++)
        {
            if (nums2[i] == 0)
            {
                val2++;
                flag2 = 1;
            }
            else
            {
                val2 = val2 + nums2[i];
            }
        }

        if (val1 == val2)
        {
            return val1;
        }
        else
        {
            if (val1 < val2)
            {
                if (flag1 == 1)
                {
                    return val2;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if (flag2 == 1)
                {
                    return val1;
                }
                else
                {
                    return -1;
                }
            }
        }

        return -1;
    }
};
