#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.size();
        int x = 0, y = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                x++;
            }
            else
            {
                mp[secret[i]]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (secret[i] != guess[i])
            {
                if (mp[guess[i]] > 0)
                {
                    y++;
                    mp[guess[i]]--;
                }
            }
        }
        string ans = to_string(x) + 'A' + to_string(y) + 'B';
        return ans;
    }
};
