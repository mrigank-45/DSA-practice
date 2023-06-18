// reverse the number
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    int reverse = 0;
    while (n != 0)
    {
        int rem = n % 10;

        // check the overflow condition
        if (reverse > INT_MAX / 10 || reverse == INT_MAX / 10 && rem > 7)
        {
            cout << "overflowed" << endl;
        }

        if (reverse < INT_MIN / 10 || reverse == INT_MIN / 10 && rem < -8)
        {
            cout << "overflowed" << endl;
        }
        // done
        
        reverse = reverse * 10 + rem;
        n = n / 10;
    }

    cout << reverse << endl;

    return 0;
}
