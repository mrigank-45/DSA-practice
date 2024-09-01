#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int valueAfterKSeconds(int n, int k)
    {
        vector<int> v(n, 1);
        int mod = 1000000007;

        while (k > 0)
        {
            vector<int> temp(n, 0);
            temp[0] = v[0];
            for (int i = 1; i < n; i++)
            {
                v[i] = (temp[i - 1] + v[i]) % mod;
                temp[i] = v[i];
            }
            k--;
        }

        return v[n - 1] % mod;
    }
};
