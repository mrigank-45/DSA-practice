#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossibleToRearrange(string s, string t, int k)
    {
        int n = s.size();
        int len = n / k;
        unordered_map<string, int> mp;
        int i = 0;
        while (i < n)
        {
            string temp = s.substr(i, len);
            sort(temp.begin(), temp.end());
            mp[temp]++;
            i += len;
        }
        i = 0;
        while (i < n)
        {
            string temp = t.substr(i, len);
            sort(temp.begin(), temp.end());
            if (mp.find(temp) == mp.end())
            {
                return false;
            }
            mp[temp]--;
            if (mp[temp] == 0)
            {
                mp.erase(temp);
            }
            i+= len;
        }
        return true;
    }
};
