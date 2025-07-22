#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(const pair<int, string> &a, const pair<int, string> &b)
    {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        int n = words.size();
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }
        vector<pair<int, string>> v;
        for (auto it : mp)
        {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), cmp);
        vector<string> ans;
        for (auto it : v)
        {
            ans.push_back(it.second);
            if (ans.size() == k)
                break;
        }
        return ans;
    }
};
