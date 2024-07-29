#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int ans = 0;

        for (int winLen = 1; winLen <= n; winLen++)
        {
            int zeros = 0;
            int ones = 0;
            int l = 0;
            int r = winLen - 1;

            for (int i = l; i <= r; i++)
            {
                if (s[i] == '0')
                {
                    zeros++;
                }
                else
                {
                    ones++;
                }
            }

            if (ones >= zeros * zeros)
            {
                ans++;
            }

            while (r < n - 1)
            {
                if (s[l] == '0')
                {
                    zeros--;
                }
                else
                {
                    ones--;
                }

                l++;
                r++;

                if (s[r] == '0')
                {
                    zeros++;
                }
                else
                {
                    ones++;
                }

                if (ones >= zeros * zeros)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
