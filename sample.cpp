#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        map<char, int> mp1;

        for (int i = 0; i < word.size(); i++)
        {
            mp1[word[i]]++;
        }

        priority_queue<int> pq;

        for (auto it : mp1)
        {
            pq.push(it.second);
        }

        int cnt = 0;
        int flag = 0;

        while (!pq.empty())
        {
            int val = pq.top();
            pq.pop();
            if (flag / 8 == 0)
            {
                cnt += val;
            }
            else if (flag / 8 == 1)
            {
                cnt += val * 2;
            }
            else if (flag / 8 == 2)
            {
                cnt += val * 3;
            }
            else
            {
                cnt += val * 4;
            }
            flag++;
        }
        return cnt;
    }
};
