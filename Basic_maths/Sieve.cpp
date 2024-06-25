#include <bits/stdc++.h>
using namespace std;

vector<bool> genPrimes(int n)
{
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i <= n; ++i)
    {
        if (prime[i])
        {
            // Update all multiples of p as non-prime
            for (int j = i + i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    return prime;
}

int main()
{
    vector<bool> primes = genPrimes(23);
    for (int i = 0; i < primes.size(); i++)
    {
        cout << i << ": " << primes[i] << "\n";
    }
    return 0;
}
