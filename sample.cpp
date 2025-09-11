#include <bits/stdc++.h>
using namespace std;

int minNumberOfFrogs(string cOf)
{
    int onGoing = 0;
    int maxOngoing = 0;
    vector<int> curr(5, 0);
    for (auto a : cOf)
    {
        if (a == 'c')
        {
            curr[0]++;
            onGoing++;
            maxOngoing = max(maxOngoing, onGoing);
        }
        else
        {
            if (a == 'r')
            {
                if (curr[0] <= curr[1])
                    return -1;
                curr[1]++;
            }
            else if (a == 'o')
            {
                if (curr[1] <= curr[2])
                    return -1;
                curr[2]++;
            }
            else if (a == 'a')
            {
                if (curr[2] <= curr[3])
                    return -1;
                curr[3]++;
            }
            else if (a == 'k')
            {
                if (curr[3] <= curr[4])
                    return -1;
                curr[4]++;
                onGoing--;
            }
        }
    }
    int total = curr[0];
    for (int i = 1; i < 5; i++)
    {
        if (curr[i] != total)
            return -1;
    }

    return maxOngoing;
}
