#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.size();

        vector<int> marked(n, 0);

        int r = 0, d = 0;

        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
            {
                r++;
            }
            else
            {
                d++;
            }
        }
        if (r == 0)
        {
            return "Dire";
        }
        if (d == 0)
        {
            return "Radiant";
        }
        int skip_r = 0, skip_d = 0;

        while (1)
        {

            for (int i = 0; i < n; i++)
            {
                if (marked[i])
                {
                    continue;
                }

                if (senate[i] == 'R')
                {
                    if (skip_r > 0)
                    {
                        skip_r--;
                        marked[i] = 1;
                    }
                    else
                    {
                        d--;
                        if (d == 0)
                        {
                            return "Radiant";
                        }
                        skip_d++;
                    }
                }
                else
                {
                    if (skip_d > 0)
                    {
                        skip_d--;
                        marked[i] = 1;
                    }
                    else
                    {
                        r--;
                        if (r == 0)
                        {
                            return "Dire";
                        }
                        skip_r++;
                    }
                }
            }
        }

        return "";
    }
};
