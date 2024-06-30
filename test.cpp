#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMidSum(int ar1[], int ar2[], int n)
    {
        vector<int> v;

        int i = 0, j = 0;

        while (i < n && j < n)
        {
            if (ar1[i] < ar2[j])
            {
                v.push_back(ar1[i]);
                i++;
            }
            else
            {
                v.push_back(ar2[j]);
                j++;
            }
        }

        while (i < n)
        {
            v.push_back(ar1[i]);
            i++;
        }
        while (j < n)
        {
            v.push_back(ar2[j]);
            j++;
        }

        int n3 = v.size();

        return v[n3 / 2] + v[n3 / 2 - 1];
    }
};
