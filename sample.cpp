#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findWinningPlayer(vector<int> &skills, int k)
    {
        int n = skills.size();
        int winner = 0;
        int streak = 0;
        for (int i = 1; i < n; i++)
        {
            if (skills[winner] < skills[i])
            {
                winner = i;
                streak = 1;
            }
            else
            {
                streak++;
            }
            if (streak == k)
            {
                return winner;
            }
        }
        return winner;
    }
};
