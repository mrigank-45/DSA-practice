#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int n, int &ans, int steps)
    {
        if (n == 1)
        {
            ans = min(ans, steps);
            return;
        }

        if (n % 3 == 0 && n/3 > 0)
        {
            solve(n / 3, ans, steps + 1);
        }
        else
        {
            solve(n - 1, ans, steps + 1);
        }
    }
    int minimumStep(int n)
    {

        int ans = INT_MAX;

        solve(n, ans, 0);

        return ans;
    }
};
