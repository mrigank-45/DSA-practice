#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinimumTime(vector<int> &strength, int k)
    {
        int n = strength.size();
        sort(strength.begin(), strength.end());

        int t = 0, x = 1, i = 0, e = 0;

        while (i < n)
        {
            if (e >= strength[i])
            {
                int j = i + 1;
                while (j < n)
                {
                    if (e >= strength[j])
                    {
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                j--;
                while (i < j)
                {
                    strength[j] = strength[j - 1];
                    j--;
                }
                i++;
                e = 0;
                x += k;
            }
            if (i == n)
                break;

            int diff = strength[i] - e;
            int op = (diff / x) + (diff % x != 0);
            t += op;
            e += op * x;
        }
        return t;
    }
};
