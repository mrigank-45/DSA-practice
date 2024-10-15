#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        unordered_map<char, int> mp;

        for (char c : s)
        {
            mp[c]++;
        }

        int ans = 0;
        for (auto it : mp)
        {
            if (it.second % 2 == 1)
            {
                ans++;
            }
            else
            {
                ans += 2;
            }
        }

        return ans;	
    }
};
