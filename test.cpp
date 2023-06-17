#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int isPossible(int N, int D) {
        int dig = N % 10;
        int sum = dig;
        if (dig == D) return 0;
        N /= 10;
        while (N) {
            dig = N % 10;
            if (dig == D || dig <= sum) return 0;
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
