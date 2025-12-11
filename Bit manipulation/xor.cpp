// Given an array of N positive integers where all numbers occur even number of times except one number which occurs odd number of times.
// Find the exceptional number.

// (a ^ a) == 0  // even times
// (a ^ a ^ a) == a  // odd times

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int arr[n];
    // take input of arr

    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num ^= arr[i];
    }
    return num;

    return 0;
}
