#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &power, int n, int i, map<int, int> &mp, vector<long long> &dp)
    {
        if (i == n)
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        long long ans = INT_MIN;

        // cast
        if (mp.find(power[i]) == mp.end() || mp[power[i]] == 0)
        {

            mp[power[i] + 1]++;
            mp[power[i] - 1]++;
            mp[power[i] + 2]++;
            mp[power[i] - 2]++;
            ans = max(ans, power[i] + solve(power, n, i + 1, mp, dp));
            mp[power[i] + 1]--;
            mp[power[i] - 1]--;
            mp[power[i] + 2]--;
            mp[power[i] - 2]--;
        }

        // not cast
        ans = max(ans, solve(power, n, i + 1, mp, dp));

        return dp[i] = ans;
    }
    long long maximumTotalDamage(vector<int> &power)
    {
        int n = power.size();
        map<int, int> mp;
        vector<long long> dp(n + 1, -1);

        return solve(power, n, 0, mp, dp);
    }
};
