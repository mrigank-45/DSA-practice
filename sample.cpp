#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.size();
        unordered_map<string, int> mp;

        for (int i = 0; i < n - 9; i++)
        {
            string temp = s.substr(i, 10);
            mp[temp]++;
        }
        vector<string> ans;
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
