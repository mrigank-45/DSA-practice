#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string s, int n, int i, int prev)
    {
        if (i == n)
        {
            return 0;
        }

        int ans = 0;

        if (s[i] - 'a' == prev + 1)
        {
            ans = max(ans, 1 + solve(s, n, i + 1, s[i] - 'a'));
        }
        
        ans = max(ans, solve(s, n, i + 1, s[i] - 'a'));

        return ans;

    }

    int longestContinuousSubstring(string s)
    {
        int n = s.size();

        return 1 + solve(s, n, 1, s[0] - 'a');
    }
};
