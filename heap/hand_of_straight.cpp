// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists
// of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can
// rearrange the cards, or false otherwise.

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {

        map<int, int> m;
        for (int i = 0; i < hand.size(); i++)
        {
            m[hand[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;

        for (auto it : m)
        {
            h.push({it.first, it.second});
        }

        while (!h.empty())
        {
            vector<pair<int, int>> v;
            int temp = h.top().first - 1;
            for (int i = 0; i < groupSize; i++)
            {
                if (h.empty())
                {
                    return false;
                }
                else
                {
                    if (h.top().first != temp + 1)
                    {
                        return false;
                    }
                    temp++;
                    v.push_back(h.top());
                    h.pop();
                }
            }
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].second > 1)
                {
                    h.push({v[i].first, v[i].second - 1});
                }
            }
        }
        return true;
    }
};
