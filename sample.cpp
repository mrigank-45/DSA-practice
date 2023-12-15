#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        map<string, int> frq;

        for (auto path : paths)
        {
            frq[path[0]] = 0;
            frq[path[1]] = 0;
        }

        for (auto path : paths)
        {
            frq[path[0]] = 2;

            if (frq[path[1]] == 2)
            {
                frq[path[1]] = 2;
            }
            else
            {
                frq[path[1]] = 1;
            }
        }

        for (auto path : paths)
        {
            if (frq[path[1]] == 1)
            {
                return path[1];
            }
        }
        return "";
    }
};
