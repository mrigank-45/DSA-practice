#include <bits/stdc++.h>
using namespace std;

// Function to calculate S(n, i)
long long stirlingSecondKind(int n, int i)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(i + 1, 0));
    dp[0][0] = 1;

    for (int ni = 1; ni <= n; ++ni)
    {
        for (int ii = 1; ii <= i; ++ii)
        {
            dp[ni][ii] = ii * dp[ni - 1][ii] + dp[ni - 1][ii - 1];
        }
    }

    return dp[n][i];
}

// Function to calculate C(x, i)
long long binomialCoefficient(int x, int i)
{
    if (i > x)
    {
        return 0;
    }
    if (i == 0 || i == x)
    {
        return 1;
    }

    if (i > x - i)
    {
        i = x - i;
    }

    long long result = 1;
    for (int k = 0; k < i; ++k)
    {
        result *= (x - k);
        result /= (k + 1);
    }

    return result;
}

// Function to i factorial
long long factorial(int i)
{
    long long result = 1;
    for (int j = 1; j <= i; ++j)
    {
        result *= j;
    }

    return result;
}

// Function for modular exponentiation: (base^exp) % mod
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

class Solution
{
public:
    int numberOfWays(int n, int x, int y)
    {
        int ans = 0;
        int mod = 1e9 + 7;

        for (int i = 1; i <= x; i++)
        {
            ans += ((((((stirlingSecondKind(n, i) % mod) * (binomialCoefficient(x, i) % mod)) % mod)
            * (factorial(i) % mod)) % mod) * (modPow(y, i, mod) % mod)) % mod;
        }
        return ans;
    }
};
