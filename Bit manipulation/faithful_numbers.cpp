// Faithful Numbers | GFG
// normal numbers have bit set as a power of 2, here we set bit as a power of 7

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long nthFaithfulNum(int N)
    {
        long int a = 0;
        int i = 0;
        while (N)
        {
            if (N & 1)
            {
                a += pow(7, i);
            }
            i++;
            N = N >> 1;
        }
        return a;
    }
};
