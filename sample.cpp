#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int limit, int index)
    {
        if (index == 3)
        {
            if (n >= 0 && n <= limit)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int ans = 0;

        for (int i = 0; i <= limit; i++)
        {
            ans += solve(n - i, limit, index + 1);
        }

        return ans;
    }
    int distributeCandies(int n, int limit)
    {
        return solve(n, limit, 1);
    }
};
