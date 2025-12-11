// Special Keyboard gfg
// explanation: www.includehelp.com/icp/special-keyboard.aspx
// we directly apply the tabulation solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int optimalKeys(int n)
    {
        int dp[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = i;
        }

        for (int i = 6; i <= n; i++)
        {
            for (int j = i - 3; j >= 1; j--)
            {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }

        return dp[n];
    }
};
