#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubstring(string S)
    {
        unordered_map<char, int> mp;
        mp['0'] = 0;
        mp['1'] = 0;
        mp['2'] = 0;
        int i = 0;
        int j = 0;
        int n = S.size();
        int ans = INT_MAX;

        while (j < n)
        {
            mp[S[j]]++;

            while (i < j)
            {
                if (mp[S[i]] > 1)
                {
                    mp[S[i]]--;
                    i++;
                }
                else
                {
                    break;
                }
            }

            if (mp['0'] >= 1 && mp['1'] >= 1 && mp['2'] >= 1)
            {
                ans = min(ans, j - i + 1);
            }
            j++;
        }

        if (ans == INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};
