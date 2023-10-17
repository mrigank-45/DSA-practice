#include <iostream>
using namespace std;

// recursion + memorization
int fibonacci(int n, int dp[])
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n]= fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
}

// tabulation
int fibonacci(int n)
{
    int dp[n + 1];

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// space optmization 
int fibonacci(int n)
{
    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = curr;
        prev2 = prev1;
    }
    return prev1;
}

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    cout << "Required fibonacci number is ";
    cout << fibonacci(n);

    cout << endl;
    return 0;
}
