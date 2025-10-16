#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        int n = shifts.size();
        int curr = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            curr += shifts[i];
            curr %= 26;
            s[i] = (s[i] - 'a' + curr) % 26 + 'a';
        }
        return s;
    }
};
