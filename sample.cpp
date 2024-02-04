#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct CompareTriple
    {
        bool operator()(const pair<pair<int, int>, int> &p1, const pair<pair<int, int>, int> &p2) const
        {
            // Compare based on the first element of the outer pair (a)
            if (p1.first.first != p2.first.first)
            {
                return p1.first.first > p2.first.first;
            }
            // If a (first element of outer pair) is equal, compare based on the second element of the outer pair (c)
            return p1.second > p2.second;
        }
    };
    int minOperations(string s1, string s2, int x)
    {
        int n = s1.size();

        vector<int> diff;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                diff.push_back(i);
            }
        }

        if (diff.size() % 2 != 0)
        {
            return -1;
        }

        // min heap
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, CompareTriple> pq;

        for (int i = 0; i < diff.size(); i++)
        {
            for (int j = i + 1; j < diff.size(); j++)
            {
                int cost = min(x, abs(diff[i] - diff[j]));
                pq.push({{diff[i], diff[j]}, cost});
            }
        }

        map<int, int> mp;
        for (int i = 0; i < diff.size(); i++)
        {
            mp[diff[i]] = 0;
        }
        int ans = 0;

        while (!pq.empty())
        {
            pair<pair<int, int>, int> p = pq.top();
            pq.pop();

            int cost = p.second;
            int i = p.first.first;
            int j = p.first.second;

            if (mp[i] == 0 && mp[j] == 0)
            {
                mp[i] = 1;
                mp[j] = 1;
                ans = ans + cost;
            }
        }

        return ans;
    }
};
