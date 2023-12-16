#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkStrings(string s1, string s2)
    {
        map<char, int> even_s1, odd_s1;
        map<char, int> even_s2, odd_s2;

        for (int i = 0; i < s1.size(); i++)
        {
            if (i % 2 == 0)
            {
                even_s1[s1[i]]++;
            }
            else
            {
                odd_s1[s1[i]]++;
            }
        }

        for (int i = 0; i < s2.size(); i++)
        {
            if (i % 2 == 0)
            {
                even_s2[s2[i]]++;
            }
            else
            {
                odd_s2[s2[i]]++;
            }
        }

        bool a = true, b = true;

        for (auto it : even_s1)
        {
            if (even_s2[it.first] != it.second)
            {
                a = false;
                break;
            }
        }

        for (auto it : odd_s1)
        {
            if (odd_s2[it.first] != it.second)
            {
                b = false;
                break;
            }
        }

        if (a && b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
