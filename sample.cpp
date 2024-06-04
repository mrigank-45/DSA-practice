#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestDivisible(string s)
    {
        int flag = 0;
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        do
        {
            if (stoi(s) % 17 == 0 && s[0] != '0')
                return s;
        } while (prev_permutation(s.begin(), s.end()));
        return "Not Possible";
    }
};
