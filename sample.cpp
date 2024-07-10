#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string lastNonEmptyString(string s)
    {
        map<char, pair<int, int>> mp;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]].first++;
            mp[s[i]].second = i;
        }
        int maxi = 1;
        for (auto it : mp)
        {
            if (it.second.first > maxi)
            {
                maxi = it.second.first;
            }
        }
        map<int, char> mp2;
        for (auto it : mp)
        {
            if (it.second.first == maxi)
            {
                mp2.insert({it.second.second, it.first});
            }
        }
        string ans = "";
        for (auto it : mp2)
        {
            ans += it.second;
        }
        return ans;
    }
};
