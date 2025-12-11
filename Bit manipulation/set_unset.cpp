// Given a 32 bit unsigned integer num and an integer i. Perform following operations on the number -
// 1. Get ith bit
// 2. Set ith bit
// 3. Clear ith bit

// Input: 70 3
// Output: 1 70 66
// Explanation: Bit at the 3rd position from LSB is 1. (1 0 0 0 1 1 0)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int num, i, a, b, c;
    cin >> num >> i;
    long long int n = num;

    n = n >> (i - 1);
    a = n & 1; // getting ith bit

    b = num | (1 << (i - 1)); // setting ith bit

    c = num & (~(1 << (i - 1))); // clearing ith bit

    cout << a << " " << b << " " << c << endl;

    return 0;
}
