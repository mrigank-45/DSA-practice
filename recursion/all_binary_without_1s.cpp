// Given an integer, K. Generate all binary strings of size k without consecutive 1’s.
// Input : K = 3  ||   Output : 000 , 001 , 010 , 100 , 101

#include <bits/stdc++.h>
using namespace std;

void solve(int k, string output, int i, char prev)
{
    if (i > k)
    {
        cout << output << endl;
        return;
    }

    // 1 case
    if (prev == '0')
    {
        prev = '1';
        output.push_back('1');
        solve(k, output, i + 1, prev);
        output.pop_back();
    }

    // 0 case
    output.push_back('0');
    prev = '0';
    solve(k, output, i + 1, prev);
    output.pop_back();
}

void PrintBinaryStrings(int k)
{
    int i = 1;
    string output;
    char prev = '0';
    solve(k, output, i, prev);
}

int main()
{
    int k = 3;

    PrintBinaryStrings(k);
}
