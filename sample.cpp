#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        int n = s.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a'].push_back(i);
        }
    }
};
