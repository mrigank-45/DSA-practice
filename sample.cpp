#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int ans = 100000;

        // case 1
        vector<int> temp1 = nums1, temp2 = nums2;
        int op1 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (temp1[i] <= temp1[n - 1])
            {
                continue;
            }
            else
            {
                swap(temp1[i], temp2[i]);
                if (temp1[i] <= temp1[n - 1] && temp2[i] <= temp2[n - 1])
                {
                    op1++;
                }
                else
                {
                    op1 = 10000;
                    break;
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (temp2[i] <= temp2[n - 1])
            {
                continue;
            }
            else
            {
                swap(temp2[i], temp1[i]);
                if (temp2[i] <= temp2[n - 1] && temp1[i] <= temp1[n - 1])
                {
                    op1++;
                }
                else
                {
                    op1 = 10000;
                    break;
                }
            }
        }
        ans = min(ans, op1);

        // case 2
        temp1 = nums1;
        temp2 = nums2;
        swap(temp1[n - 1], temp2[n - 1]);
        int op2 = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (temp1[i] <= temp1[n - 1])
            {
                continue;
            }
            else
            {
                swap(temp1[i], temp2[i]);
                if (temp1[i] <= temp1[n - 1] && temp2[i] <= temp2[n - 1])
                {
                    op2++;
                }
                else
                {
                    op2 = 10000;
                    break;
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (temp2[i] <= temp2[n - 1])
            {
                continue;
            }
            else
            {
                swap(temp2[i], temp1[i]);
                if (temp2[i] <= temp2[n - 1] && temp1[i] <= temp1[n - 1])
                {
                    op2++;
                }
                else
                {
                    op2 = 10000;
                    break;
                }
            }
        }
        ans = min(ans, op2);

        return ans >= 10000 ? -1 : ans;
    }
};
