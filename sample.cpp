#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> z_fn(string &s)
    {
        int n = s.size(), l = 0, r = 0;
        vector<int> z(n);
        for (int i = 1; i < n; i++)
        {
            if (i > r)
            {
                l = r = i;
                while (r < n && s[r] == s[r - l])
                    r++;
                z[i] = r - l;
                r--;
            }
            else
            {
                int cur = i - l;
                if (z[cur] + i < r + 1)
                    z[i] = z[cur];
                else
                {
                    l = i;
                    while (r < n && s[r] == s[r - l])
                        r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        map<string, vector<int>> mp;
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            string s = words[i];
            vector<int> z = z_fn(s);
            mp[s] = z;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (words[i].size() > words[j].size())
                {
                    continue;
                }
                if (words[i].size() == words[j].size())
                {
                    if (words[i] == words[j])
                    {
                        cnt++;
                    }
                    continue;
                }
                string temp = words[j].substr(0, words[i].size());
                if(temp == words[i] && mp[words[j]][words[j].size() - words[i].size()] == words[i].size())
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
