// Minimum Size Subarray in Infinite Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSizeSubarray(vector<int> &v, int k)
    {
        int n = v.size();
        long long s = 0;

        for (auto i : v)
        {
            s = s + i;
        }

        if (k % s == 0)
        {
            return (k / s) * n;
        }

        long long x = (long long)(k / s) * n;
        k = k - (s * (k / s));

        for (int i = 0; i < n; i++)
        {
            v.push_back(v[i]);
        }

        int i = 0, j = 0;

        long long int sum = v[0];
        int ans = INT_MAX;

        while (i < 2 * n && j < 2 * n)
        {
  

            if (sum == k)
            {
                ans = min(ans, j - i + 1);
                if (i != j)
                {
                    sum = sum - v[i];
                    i++;
                }
                else
                {
                    if (j != 2 * n - 1)
                    {
                        sum = sum + v[j + 1];
                    }
                    j++;
                }
            }
            else if (sum < k)
            {
                if (j != 2 * n - 1)
                {
                    sum = sum + v[j + 1];
                }
                j++;
            }
            else
            {
                if (i != j)
                {
                    sum = sum - v[i];
                    i++;
                }
                else
                {
                    if (j != 2 * n - 1)
                    {
                        sum = sum + v[j + 1];
                    }
                    j++;
                }
            }
        }

        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans + x;
    }
};
