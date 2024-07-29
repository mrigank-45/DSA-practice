#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLength(int n, string s)
    {
        unordered_map<char,int> mp;

        for(int i = 0; i<n; i++){
            mp[s[i]]++;
        }

        return mp.size();
    }
};
