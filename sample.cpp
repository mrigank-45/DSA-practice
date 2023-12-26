#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSum(int n, int k)
    {
        int sum = 0;
        int i = 0;
        while (n)
        {
            i++;
            cout << "n: " << n << endl;
            cout << "i: " << i << endl;
            cout << "sum: " << sum << endl;

            if (i == k / 2)
            {
                if (k % 2 == 0)
                {
                    sum += i;
                    n--;
                    i += k / 2 - 1;
                    continue;
                }
                else
                {
                    sum += i;
                    n--;
                    i += k / 2;
                    continue;
                }
            }

            sum += i;
            n--;
        }

        return sum;
    }
};
