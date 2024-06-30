#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int solve(string s, int k)
    {
        int n = s.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        long long int ans = 0;
        // map<int, int> mp;
        vector<int> mp(26, 0);

        while (j < n)
        {
            mp[s[j] - 'a']++;

            if (mp[s[j] - 'a'] == 1)
            {
                cnt++;
            }

            while (cnt > k)
            {
                mp[s[i] - 'a']--;
                if (mp[s[i] - 'a'] == 0)
                {
                    cnt--;
                }
                i++;
            }

            ans = ans + j - i + 1;
            j++;
        }

        return ans;
    }
    long long int substrCount(string s, int k)
    {
        return solve(s, k) - solve(s, k - 1);
    }
};
