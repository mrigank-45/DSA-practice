#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minChanges(string s)
    {
        int n = s.size();

        int cnt = 0;
        char flag;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) // even
            {
                flag = s[i];
            }
            else // odd
            {
                if (s[i] != flag)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
