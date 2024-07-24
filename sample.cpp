#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long nCr(long long n, long long r)
    {
        double sum = 1;
        for (int i = 1; i <= r; i++)
        {
            sum = sum * (n - r + i) / i;
        }
        return (long long)sum;
    }
    long long countSubstrings(string s, char c)
    {
        long long cnt = 0;
        for (long long i = 0; i < s.size(); i++)
        {
            if(s[i] == c)
            {
                cnt++;
            }
        }
        long long ans = nCr(cnt,2) + cnt;

        return ans;

    }
};
