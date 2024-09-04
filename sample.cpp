#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countCompleteDayPairs(vector<int> &hours)
    {
        int n = hours.size();
        map<int, int> mp;
        long long cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int modVal = hours[i] % 24;
            int complement = (24 - modVal) % 24;

            if (mp.find(complement) != mp.end())
            {
                cnt += mp[complement];
            }
            mp[modVal]++;
        }
        return cnt;
    }
};
