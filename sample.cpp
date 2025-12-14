#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        int n = s.size(), k = indices.size(), i = 0, j = 0;
        string ans = "";

        vector<pair<int,pair<string,string>> > v;
        for(int idx=0; idx<k; idx++)
        {
            v.push_back({indices[idx], {sources[idx], targets[idx]}});
        }
        sort(v.begin(), v.end());

        while (i < n)
        {
            if (j<k && i == v[j].first)
            {
                if (s.substr(i, v[j].second.first.length()) == v[j].second.first)
                {
                    ans += v[j].second.second;
                    i += v[j].second.first.length();
                    j++;
                }
                else
                {
                    ans += s[i];
                    i++;
                    j++;
                }
            }
            else
            {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};
