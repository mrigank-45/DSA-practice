#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool doesAliceWin(string s)
    {
        int n = s.size();

        int v = 0;

        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]))
            {
                v++;
            }
        }

        if (v == 0)
        {
            return false;
        }
        return true;
    }
};
