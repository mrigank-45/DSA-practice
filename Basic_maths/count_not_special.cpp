// Find the Count of Numbers Which Are Not Special

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> genPrimes(int n)
    {
        vector<bool> prime(n + 1, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i <= n; ++i)
        {
            if (prime[i])
            {
                for (int j = i + i; j <= n; j += i)
                {
                    prime[j] = false;
                }
            }
        }

        return prime;
    }
    int nonSpecialCount(int l, int r)
    {
        vector<bool> primes = genPrimes(sqrt(r));
        int cnt = 0;

        int i = 1;
        while(i * i <= r)
        {
            int x = i * i;
            if(x >= l && primes[i])
            {
                cnt++;
            }
            i++;
        }
        return r - l - cnt + 1;
    }
};
