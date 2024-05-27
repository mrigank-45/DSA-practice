#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int curr, int temp)
    {
        if (curr > n)
        {
            return 10000;
        }

        if (curr == n)
        {
            return 0;
        }

        // Copy
        int copySteps = 10000;
        if (curr != temp)
        {
            copySteps = 1 + solve(n, curr, curr);
        }

        // Paste
        int pasteSteps = 10000;
        if (temp != 0)
        {
            pasteSteps = 1 + solve(n, curr + temp, temp);
        }

        return min(copySteps, pasteSteps);
    }

    int minSteps(int n)
    {
        return solve(n, 1, 0);
    }
};
