#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        int n = strs.size();
        vector<string> strs1 = strs;

        for (int i = 0; i < n; i++)
        {
            sort(strs1[i].begin(), strs1[i].end());
        }

        map<string, pair<bool, vector<int>>> mp;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(strs1[i]) == mp.end())
            {
                mp[strs1[i]] = {true, {i}};
            }
            else
            {
                mp[strs1[i]].second.push_back(i);
            }
        }

        vector<vector<string>> ans;

        for(auto it: mp)
        {
            vector<string> temp;
            for(auto i: it.second.second)
            {
                temp.push_back(strs[i]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
