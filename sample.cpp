#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(int n)
    {

        int ans = 0;
        if (n % 2 == 1)
        {
            int i = n/2;
            int val = 2*i + 1;

            while (i >= 0)
            {
                ans += val - (2*i + 1);
                i--;
            }
        }
        else{
            int i = n/2;
            int val = 2*i + 1;
            val--;
            i--;

            while (i >= 0)
            {
                ans += val - (2*i + 1);
                i--;
            }
        }

        return ans;
    };
};
