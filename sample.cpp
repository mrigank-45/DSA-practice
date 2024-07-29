#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {

        int ans = 0, empty = 0, full = numBottles;

        while (full > 0)
        {
            ans += full;
            empty += full;
            full = 0;
            if (empty >= numExchange)
            {
                full++;
                empty -= numExchange;
                numExchange++;
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};
