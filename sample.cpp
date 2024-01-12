#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        map<int, int> m;
        string temp;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                m[i] = 1;
                temp.push_back(s[i]);
            }
            else
            {
                m[i] = 0;
            }
        }
        sort(temp.begin(), temp.end());
        int j = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (m[i])
            {
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};
