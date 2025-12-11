// Given two positive integers L, R and a digit D, find out all the good numbers in the range [L, R], which do not contain the digit D.
// A number is a good number if it's every digit is larger than the sum of digits which are on the right side of that digit.
// 9620  is good as (2 > 0, 6 > 2+0, 9 > 6+2+0)

// Input: L=100 R=500 D=5
// Output: {210, 310, 320, 410, 420, 421, 430}

#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int isPossible(int N, int D)
{
    int dig = N % 10;
    int sum = dig;
    if (dig == D)
        return 0;
    N /= 10;
    while (N)
    {
        dig = N % 10;
        if (dig == D || dig <= sum)
            return 0;
        sum += dig;
        N /= 10;
    }
    return 1;
}

void goodNumbers(int l, int r, int d)
{
    // base case
    if (l == r)
    {
        if (isPossible(l, d))
        {
            v.push_back(l);
        }
        return;
    }
    else if (r < l)
    {
        return;
    }

    if (isPossible(l, d))
    {
        v.push_back(l);
    }
    if (isPossible(r, d))
    {
        v.push_back(r);
    }
    l++;
    r--;
    goodNumbers(l, r, d);
}

int main()
{
    goodNumbers(200, 700, 4);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
