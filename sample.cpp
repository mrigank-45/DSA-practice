#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> seive(int n)
    {
        vector<bool> prime(n + 1, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                for (int j = i + i; j <= n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        vector<bool> prime = seive(n);

        map<int, vector<int>> adj;

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    }
};
