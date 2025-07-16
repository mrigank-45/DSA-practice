#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int k) {
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
            for (int i = 0; i < k; i++)
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
