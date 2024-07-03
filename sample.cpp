#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        if (a == e && (c != a || d < min(b, f) || d > max(b, f)))
        {
            return 1;
        }
        else if (b == f && (d != b || c < min(a, e) || c > max(a, e)))
        {
            return 1;
        }
        else if (c + d == e + f && (c + d != a + b || a < min(c, e) || a > max(c, e)))
        {
            return 1;
        }
        else if (c - d == e - f && (c - d != a - b || b < min(d, f) || b > max(d, f)))
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
};
