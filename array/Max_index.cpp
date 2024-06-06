// Maximum Index | GFG
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIndexDiff(int a[], int n)
    {
        int leftMin[n];
        int rightMax[n];

        leftMin[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            leftMin[i] = min(a[i], leftMin[i - 1]);
        }

        rightMax[n - 1] = a[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            rightMax[j] = max(a[j], rightMax[j + 1]);
        }

        int i = 0;
        int j = 0;
        int maxDiff = -1;

        while (i < n && j < n)
        {
            if (leftMin[i] <= rightMax[j])
            {
                maxDiff = max(maxDiff, j - i);
                j = j + 1;
            }
            else
            {
                i = i + 1;
            }
        }

        return maxDiff;
    }
};
