#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;

        for (int idx = n - 1; idx >= 0; --idx)
        {
            if (s[idx] == '0')
            {
                dp[idx] = 0;
            }
            else
            {
                int oneDigitWays = dp[idx + 1];
                int twoDigitWays = 0;
                if (idx + 1 < n)
                {
                    int firstDigit = s[idx] - '0';
                    int secondDigit = s[idx + 1] - '0';
                    int combo = firstDigit * 10 + secondDigit;
                    if (combo <= 26)
                    {
                        twoDigitWays = dp[idx + 2];
                    }
                }
                dp[idx] = oneDigitWays + twoDigitWays;
            }
        }
        return dp[0];
    }
};
