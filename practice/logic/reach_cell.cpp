//  Determine if a Cell Is Reachable at a Given Time

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        if (sx == fx && sy == fy)
        {
            return (t > 1 || t == 0);
        }

        int k = max(abs(sy - fy), abs(fx - sx));
        
        if (k <= t)
        {
            return true;
        }
        return false;
    }
};
