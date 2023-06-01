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
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }

    cout<<reverse<<endl;

    return 0;
}
