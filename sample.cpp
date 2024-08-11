#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<string, int> dp;

    bool equal(map<char, int> &mp)
    {
        int freq = mp.begin()->second;
        for (auto it : mp)
        {
            if (it.second != freq)
                return false;
        }
        return true;
    }
    string getkey(map<char, int> &mp)
    {
        string key = "";
        for (auto it : mp)
        {
            key += it.first;
            key += to_string(it.second);
        }
        return key;
    }
    int solve(string s, int n, int i, map<char, int> &mp)
    {
        if (i == n)
        {
            if (mp.size() == 0)
                return 0;
            if (equal(mp))
                return 1;
            else
                return 10000;
        }
        string temp = getkey(mp) + "#" + to_string(i);

        if(dp.find(temp) != dp.end())
            return dp[temp];

        mp[s[i]]++;
        int ans = 10000;

        if (equal(mp))
        {
            map<char, int> temp;
            ans = min(ans, 1 + solve(s, n, i + 1, temp));
        }

        ans = min(ans, solve(s, n, i + 1, mp));

        return dp[temp] = ans;
    }
    int minimumSubstringsInPartition(string s)
    {
        int n = s.size();
        map<char, int> temp;
        return solve(s, n, 0, temp);
    }
};
