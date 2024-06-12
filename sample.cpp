#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areKAnagrams(string str1, string str2, int k)
    {
        if (str1.length() != str2.length())
        {
            return false;
        }
        map<char, int> mp1;
        map<char, int> mp2;

        for (int i = 0; i < str1.length(); i++)
        {
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }

        int a = 0;
        int b = 0;

        for (auto i : mp1)
        {
            if (i.second > mp2[i.first])
            {
                a += i.second - mp2[i.first];
            }
        }

        for (auto i : mp2)
        {
            if (i.second > mp1[i.first])
            {
                b += i.second - mp1[i.first];
            }
        }

        if (a == b && a <= k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
