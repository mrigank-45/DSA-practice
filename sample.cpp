#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(int k)
    {
        int ans = INT_MAX;

        for (int i = 0; i <= k; i++)
        {
            int moves = i;
            int val = i + 1;
            if (k % val == 0)
            {
                moves += (k / val) - 1;
            }
            else
            {
                moves += k / val;
            }
            ans = min(ans, moves);
        }

        return ans;
    }
};
