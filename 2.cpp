#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(string s, unordered_map<string, bool> &mp, string temp, int i, int n, vector<int> &memo)
    {
        if (i == n)
        {
            return temp == "";
        }

        if (memo[i] != -1)
        {
            return memo[i];
        }

        temp += s[i];

        if (mp[temp] && solve(s, mp, "", i + 1, n, memo))
        {
            return memo[i] = true;
        }

        if (solve(s, mp, temp, i + 1, n, memo))
        {
            return memo[i] = true;
        }

        return memo[i] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> mp;
        for (const auto &word : wordDict)
        {
            mp[word] = true;
        }

        int n = s.size();
        vector<int> memo(n, -1);
        return solve(s, mp, "", 0, n, memo);
    }
};
