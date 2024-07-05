#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        int e = 0, o = 0;
        if (n % 2 == 0)
        {
            e = n / 2;
            o = n / 2;
        }
        else
        {
            e = ((n - 1) / 2);
            o = ((n - 1) / 2) + 1;
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (i % 2 == 0)
            {
                ans += o;
            }
            else
            {
                ans += e;
            }
        }
        return ans;
    }
};
