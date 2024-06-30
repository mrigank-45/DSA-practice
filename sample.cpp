#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(int n)
    {
        int cnt = 0;
        while (n>0)
        {
            if (n & 1)
            {
                cnt++;
            }
            n = n >> 1;
        }
        return cnt;
    }
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            ans[i] = count(i);
        }

        return ans;
    }
};
