#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int count = 0;
        for (int winLen = 1; winLen <= n; winLen++)
        {
            int zeroCount = 0;
            float maxZero = sqrt(winLen);
            int l = 0;
            int r = winLen;
            for (int i = l; i < r; i++)
            {
                if (s[i] == '0')
                    zeroCount++;
            }
            if (zeroCount < maxZero)
                count++;
            while (r < n)
            {
                if (s[r] == '0' && s[l] != '0')
                {
                    zeroCount++;
                }
                else if (s[r] != '0' && s[l] == '0')
                {
                    zeroCount--;
                }
                l++;
                r++;
                if (zeroCount < maxZero)
                    count++;
            }
        }
        return count;
    }
};
