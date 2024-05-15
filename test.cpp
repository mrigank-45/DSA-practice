#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int node, int n, int &ans, int steps)
    {
        if (node > n)
        {
            return;
        }
        if (node == n)
        {
            ans = min(ans, steps);
        }

        if (node * 3 <= n)
        {
            solve(node * 3, n, ans, steps + 1);
        }
        else
        {
            solve(node + 1, n, ans, steps + 1);
        }
    }
    int minimumStep(int n)
    {

        int ans1 = INT_MAX;
        int ans2 = INT_MAX;

        solve(1, n, ans1, 0);
        solve(2, n, ans2, 0);

        return min(ans1, ans2 + 1);
    }
};
