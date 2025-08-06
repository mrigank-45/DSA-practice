#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][2001];
    int solve(int i, int prev, vector<vector<int>> &pairs, int n)
    {
        if (i == n)
            return 0;

        if (dp[i][prev + 1000] != -1)
            return dp[i][prev + 1000];

        int ans = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (pairs[j][0] > prev)
            {
                ans = max(ans, 1 + solve(j, pairs[j][1], pairs, n));
            }
        }
        return dp[i][prev + 1000] = ans;
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        memset(dp, -1, sizeof(dp));
        sort(pairs.begin(), pairs.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i][pairs[i][1] +1000] = solve(i, pairs[i][1], pairs, n);
            ans = max(ans, 1 + dp[i][pairs[i][1] + 1000]);
        }
        return ans;
    }
};
