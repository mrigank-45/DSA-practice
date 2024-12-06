#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(string s)
    {
        int n = s.size();
        int cnt = 0, ans = 0;

        if (s[0] == '1')
            cnt++;

        for (int i = 1; i < n; i++)
        {
            // last element
            if (i == n - 1)
            {
                if (s[i] == '1')
                {
                    if (s[i - 1] != '1')
                    {
                        ans += cnt;
                    }
                }
                else
                {
                    ans += cnt;
                }
                break;
            }

            if (s[i] == '1')
            {
                if (s[i - 1] != '1')
                {
                    ans += cnt;
                    cnt++;
                }
                else{
                    cnt++;
                }
            }
        }

        return ans;
    }
};
