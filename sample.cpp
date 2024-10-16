#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string s, int n, int i, int sum, vector<vector<int>> &dp)
    {
        if (i == n - 1)
        {
            sum = sum * 10 + (s[i] - '0');
            if (sum <= 26 && sum != 0)
            {
                return 1;
            }
            return 0;
        }

        sum = sum * 10 + (s[i] - '0');

        if (sum > 26)
            return 0;

        if (sum == 0 && i != 0 && s[i - 1] == '0')
            return 0;
        
        if(dp[i][sum] != -1) return dp[i][sum];

        int ans = 0;

        // partition
        if (i != n - 1 && s[i + 1] != '0' && sum != 0)
        {
            ans += solve(s, n, i + 1, 0, dp);
        }

        // not partition
        ans += solve(s, n, i + 1, sum, dp);

        return dp[i][sum] = ans;
    }
    int numDecodings(string s)
    {
        int n = s.size();

        if (s[0] == '0')
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(27, -1));

        return solve(s, n, 0, 0, dp);
    }
};
