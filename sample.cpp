#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.size();
        map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }
        char odd = '#';
        string half = "";
        for (auto &p : freq)
        {
            if (p.second % 2 == 1)
            {
                odd = p.first;
            }
            half += string(p.second / 2, p.first);
        }
        string otherHalf = half;
        reverse(otherHalf.begin(), otherHalf.end());
        if (odd != '#')
        {
            half += odd;
        }

        half += otherHalf;
        return half;
    }
};
