#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        int n = a.size();
        if (b.size() <= n)
        {
            bool flag = false;
            for (int i = 0; i <= a.size() - b.size(); i++)
            {
                if (a.substr(i, b.size()) == b)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                return 1;
            }
        }
        if (b.size() < 2 * n)
        {
            bool flag2 = false;
            string a1 = a + a;
            for (int i = 0; i <= a1.size() - b.size(); i++)
            {
                if (a1.substr(i, b.size()) == b)
                {
                    flag2 = true;
                    break;
                }
            }
            if (flag2)
            {
                return 2;
            }
        }
        int ans = 0;
        string s1 = "", s2 = "";
        int i = 0;
        while (i < b.size())
        {
            if (b.substr(i, n) == a)
            {
                while (b.substr(i, n) == a)
                {
                    i += n;
                    ans++;
                    if (i + n > b.size())
                    {
                        break;
                    }
                }
                s2 = b.substr(i, b.size() - i);
                break;
            }
            else
            {
                s1 += b[i];
                i++;
            }
        }

        if (s1.size() < n && s2.size() < n && a.substr(n - s1.size(), s1.size()) == s1 && a.substr(0, s2.size()) == s2)
        {
            ans = ans + (s1.size() != 0) + (s2.size() != 0);
            return ans;
        }
        else
        {
            return -1;
        }
    }
};
