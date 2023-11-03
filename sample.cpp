#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int sx, int sy, int fx, int fy, long long int t)
    {

        if (sx < 1 || sy < 1)
        {
            return false;
        }

        if (t == 0)
        {
            if (sx == fx && sy == fy)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool c1 = solve(sx + 1, sy, fx, fy, t - 1);

        bool c2 = solve(sx, sy + 1, fx, fy, t - 1);

        bool c3 = solve(sx - 1, sy, fx, fy, t - 1);

        bool c4 = solve(sx, sy - 1, fx, fy, t - 1);

        bool c5 = solve(sx + 1, sy + 1, fx, fy, t - 1);

        bool c6 = solve(sx - 1, sy - 1, fx, fy, t - 1);

        bool c7 = solve(sx + 1, sy - 1, fx, fy, t - 1);

        bool c8 = solve(sx - 1, sy + 1, fx, fy, t - 1);

        if (c1 || c2 || c3 || c4 || c5 || c6 || c7 || c8)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        return solve(sx, sy, fx, fy, t);
    }
};
