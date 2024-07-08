#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
    string shortestPalindrome(string s)
    {
        int n = s.size();
        int k = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isPalindrome(s.substr(0, i)))
            {
                k = i;
            }
        }
        if (k == n)
        {
            return s;
        }

        string temp = s.substr(k);
        reverse(temp.begin(), temp.end());
        string ans = temp + s;
        return ans;
    }
};
