#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(string s, unordered_map<string, bool> &mp, int i, int n, vector<int> &memo)
    {
        if (i == n)
        {
            return true;
        }

        if (memo[i] != -1)
        {
            return memo[i];
        }

        string temp;
        for (int j = i; j < n; ++j)
        {
            temp += s[j];

            // if temp is present, then check for remaining string, if true, only then return
            // else go for next string
            if (mp[temp] && solve(s, mp, j + 1, n, memo))
            {
                return memo[i] = true;
            }
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
        return solve(s, mp, 0, n, memo);
    }
};
