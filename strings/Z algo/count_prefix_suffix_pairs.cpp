// Count Prefix and Suffix Pairs II
// By calculating all the prefixes of the string and checking if this string is already present in the map, we are avoiding nested loops for calculating pairs.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> z_function(string s)
    {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (i < r)
            {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            {
                z[i]++;
            }
            if (i + z[i] > r)
            {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        // {string, count of string till now}
        map<string, long long> mp;

        long long res = 0;
        for (string s : words)
        {
            vector<int> z = z_function(s);
            string temp = "";
            int n = s.size();
            for (int i = n - 1; i >= 0; i--)
            {
                temp.push_back(s[n - i - 1]);        // calculate all the prefixes of the string
                if (z[i] == n - i && mp.count(temp)) // check if the prefix is also a suffix and this string has occured before
                {
                    res += mp[temp];
                }
            }
            if (mp.count(s))
                res += mp[s];

            mp[s]++;
        }

        return res;
    }
};
