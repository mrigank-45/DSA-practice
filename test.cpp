#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int x, int y, int z, string &ans)
    {
        if (ans.back() == 'x')
        {
            if (y > 0)
            {
                ans.push_back('y');
                y--;
            }
            else
            {
                return;
            }
        }
        else if (ans.back() == 'y')
        {
            if (y > 0 && x > 0)
            {
                ans.push_back('x');
                x--;
            }
            else if (z > 0)
            {
                ans.push_back('z');
                z--;
            }
            else
            {
                return;
            }
        }
        else
        {
            if (y > 0 && x > 0)
            {
                ans.push_back('x');
                x--;
            }
            else if (z > 0)
            {
                ans.push_back('z');
                z--;
            }
            else
            {
                return;
            }
        }
    }
    int longestString(int x, int y, int z)
    {
        string ans1;
        ans1.push_back('x');
        x--;
        solve(x, y, z, ans1);

        string ans2;
        ans2.push_back('y');
        y--;
        solve(x, y, z, ans2);

        string ans3;
        ans3.push_back('z');
        z--;
        solve(x, y, z, ans3);

        return 2 * (max(ans1.length(), max(ans2.length(), ans3.length())));
    }
};
