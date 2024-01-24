#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> SieveOfEratosthenes(int n)
    {
        // Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        vector<bool> prime(n + 1, true);
        prime[0] = false;
        prime[1] = false;

        for (int p = 2; p * p <= n; p++)
        {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true)
            {
                // Update all multiples of p greater than or
                // equal to the square of it. Numbers which are
                // multiples of p and are less than p^2 are
                // already marked.
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        return prime;
    }

    vector<vector<int>> findPrimePairs(int n)
    {
        if (n == 1 || n == 2)
        {
            return {};
        }
        vector<bool> is_prime = SieveOfEratosthenes(n);

        if (n == 10)
        {
            cout << is_prime[5] << endl;
        }

        vector<vector<int>> ans;
        for (int i = 2; i <= n / 2; i++)
        {
            if (is_prime[i] && is_prime[n - i])
            {
                ans.push_back({i, n - i});
            }
        }
        return ans;
    }
};
