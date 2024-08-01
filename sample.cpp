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
    int maximumPrimeDifference(vector<int> &nums)
    {
        vector<bool> isPrime = genPrimes(101);
        vector<int> v;

        for (int i = 0; i < nums.size(); i++)
        {
            if (isPrime[nums[i]])
            {
                v.push_back(i);
            }
        }

        if (v.size() == 0)
        {
            return -1;
        }
        else
        {
            return v.back() - v.front();
        }
    }
};
