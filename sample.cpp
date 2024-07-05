#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(int i, int k, map<int, vector<int>> &mp, int n)
    {
        unordered_map<int, bool> vis;
        queue<int> q;

        q.push(i);
        vis[i] = true;

        while (!q.empty() && k > 0)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();

                for (auto it : mp[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
            k--;
        }
        return q.size();
    }

    vector<int> countOfPairs(int n, int x, int y)
    {
        map<int, vector<int>> mp;

        for (int i = 0; i < n - 1; i++)
        {
            mp[i].push_back(i + 1);
            mp[i + 1].push_back(i);
        }
        if (x - 1 != y || y - 1 != x)
        {
            mp[x - 1].push_back(y - 1);
            mp[y - 1].push_back(x - 1);
        }

        vector<int> res(n, 0);
        for (int k = 1; k <= n; k++)
        {
            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                int out = bfs(i, k, mp, n);
                if (k == 2)
                {
                    cout << out << endl;
                }
                temp += out;
            }
            res[k - 1] = temp;
        }
        return res;
    }
};
