#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        string ans = "";
        if (mp.find(key) == mp.end())
        {
            return ans;
        }

        int l = 0, r = mp[key].size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mp[key][mid].first <= timestamp)
            {
                ans = mp[key][mid].second;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
