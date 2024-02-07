#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLexicographicallySmaller(string a, string b)
    {
        for (int i = 0; i < a.length(); ++i)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            else if (a[i] < b[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        return false;
    }

    string shortestBeautifulSubstring(string s, int k)
    {
        vector<int> index;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                index.push_back(i);
            }
        }

        if (k > index.size())
        {
            return "";
        }

        int cnt = INT_MAX;
        pair<int, int> p = {0, 0};

        int l = 0;
        int r = k - 1;

        while (r < index.size())
        {
            if (index[r] - index[l] + 1 < cnt)
            {
                cnt = index[r] - index[l] + 1;
                p = {index[l], index[r]};
            }
            else if (index[r] - index[l] + 1 == cnt)
            {
                if (isLexicographicallySmaller(s.substr(index[l], index[r] - index[l] + 1), s.substr(p.first, p.second - p.first + 1)))
                {
                    p = {index[l], index[r]};
                }
            }
            l++;
            r++;
        }

        return s.substr(p.first, p.second - p.first + 1);
    }
};
