#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        int mod = 1e9 + 7;
        if (m == n)
        {
            return (m - 1) * (n - 1);
        }
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(), hFences.end());
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end());

        set<int> s1;
        set<int> s2;

        int ans = -1;

        for (int i = 0; i < vFences.size(); i++)
        {
            for (int j = i + 1; j < vFences.size(); j++)
            {
                int b = vFences[j] - vFences[i];
                s1.insert(b);
            }
        }

        for (int i = 0; i < hFences.size(); i++)
        {
            for (int j = i + 1; j < hFences.size(); j++)
            {
                int b = hFences[j] - hFences[i];
                s2.insert(b);
            }
        }

        for (auto i : s1)
        {
            for (auto j : s2)
            {
                if (i == j)
                {
                    ans = max(ans, i * j) % mod;
                }
            }
        }

        return ans % mod;
    }
};
