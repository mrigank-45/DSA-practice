#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct compare
    {
        bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
        {
            if (p1.first == p2.first)
            {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };
    string clearStars(string s)
    {
        int n = s.size();
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;

        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                int index = pq.top().second;
                mp[index] = true;
                pq.pop();
            }
            else
            {
                pq.push({s[i], i});
            }
        }
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            if (mp[i] == true || s[i] == '*')
            {
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
