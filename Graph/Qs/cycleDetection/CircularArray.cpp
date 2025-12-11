// Circular Array Loop (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int i, int sign, vector<int> &a, vector<int> &vis, vector<int> &pathVis, int n)
    {
        vis[i] = 1;
        pathVis[i] = 1;

        long long jump = (long long)i + a[i];
        jump = ((jump % n) + n) % n;
        int next = (int)jump;

        if (sign * a[next] < 0)
            return false;

        if (next == i)
            return false;

        if (pathVis[next])
            return true;

        if(vis[next] == 0 && dfs(next, sign, a, vis, pathVis, n))  return true;
        pathVis[i] = 0;
        return false;
    }

public:
    bool circularArrayLoop(vector<int> &a)
    {
        int n = a.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                vector<int> pathVis(n, 0);
                int sign = 1;
                if (a[i] < 0)
                    sign = -1;
                if (dfs(i, sign, a, vis, pathVis, n))
                    return 1;
            }
        }
        return 0;
    }
};
