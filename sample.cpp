#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &power, int n, int i, map<int, int> &mp, vector<long long> &dp, vector<int> &nextIndex)
    {
        if (i >= n)
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        long long ans = INT_MIN;
        long long product = ((long long)mp[power[i]] * (long long)power[i]);

        ans = max(ans, product + solve(power, n, nextIndex[i], mp, dp, nextIndex));

        ans = max(ans, solve(power, n, i + mp[power[i]], mp, dp, nextIndex));

        return dp[i] = ans;
    }

    long long maximumTotalDamage(vector<int> &power)
    {
        int n = power.size();
        sort(power.begin(), power.end());
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[power[i]]++;
        }

        vector<long long> dp(n, -1);
        vector<int> nextIndex(n);  

        for (int i = 0; i < n; i++)
        {
            int val = power[i] + 2;
            nextIndex[i] = upper_bound(power.begin(), power.end(), val) - power.begin();
        }

        return solve(power, n, 0, mp, dp, nextIndex);
    }
};
