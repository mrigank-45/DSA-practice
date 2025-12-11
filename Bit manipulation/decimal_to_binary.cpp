// convert decimal number to binary

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    int num = 0;
    int i = 0;

    while (n)
    {
        int digit = n & 1;                // gives the last bit
        num = (digit * pow(10, i)) + num; // formulating the binary num from bits

        n = n >> 1;
        i++;
    }
    cout << num << endl;

    return 0;
}
