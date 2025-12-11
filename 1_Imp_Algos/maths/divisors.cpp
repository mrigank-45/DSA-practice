// print all the divisors of a given number.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    for (int i = 1; i <= sqrt(n); i++) // just itrate till the square root of num.
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
            {
                cout << n / i << " "; // 4 as a divisor of 36 also gives 9 as divisor
            }
        }
    }

    return 0;
}
// same approach for checking if a number is prime or not.
