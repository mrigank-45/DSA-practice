#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTotalSum(vector<int> &maximumHeight)
    {
        int n = maximumHeight.size();
        long long sum = 0;
        sort(maximumHeight.begin(), maximumHeight.end());
        reverse(maximumHeight.begin(), maximumHeight.end());
        int h = maximumHeight[0];
        sum += h;
        for(int i = 1; i < n; i++)
        {
            if(maximumHeight[i] < h)
            {
                sum += maximumHeight[i];
                h = maximumHeight[i];
            }
            else
            {
                if(h-1 <= 0)
                {
                    return -1;
                }
                sum += h - 1;
                h--;
            }
        }
        return sum;
    }
};
