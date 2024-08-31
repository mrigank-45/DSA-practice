#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findWinningPlayer(vector<int> &skills, int k)
    {
        int n = skills.size();
        deque<int> q;
        unordered_map<int, int> index;

        for (int i = 0; i < n; i++)
        {
            index[skills[i]] = i;
            q.push_back(skills[i]);
        }

        int cnt = 0;
        int current_winner = q.front();
        q.pop_front();

        while (!q.empty())
        {
            int challenger = q.front();
            q.pop_front();

            if (current_winner > challenger)
            {
                cnt++;
                q.push_back(challenger);
            }
            else
            {
                cnt = 1;
                q.push_back(current_winner);
                current_winner = challenger;
            }

            if (cnt == k)
            {
                break;
            }
        }

        return index[current_winner];
    }
};
