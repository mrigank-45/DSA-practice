#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        int n = coins.size();
        unordered_map<int, bool> mp;

        int cnt = 0;

        // min priority queue
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; // {val,adder}

        for (int i = 0; i < n; i++)
        {
            pq.push({coins[i], coins[i]});
        }

        while (1)
        {
            pair<int, int> p = pq.top();
            pq.pop();

            if (mp[p.first] == false)
            {
                mp[p.first] = true;
                cnt++;
            }

            if (cnt == k)
            {
                return p.first;
            }

            pq.push({p.first + p.second, p.second});
        }
    }
};
