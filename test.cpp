#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &s1, string &s2, int i, int n)
    {
        if (i == n)
        {
            return 0;
        }

        if (s1[i] == s2[i])
        {
            return solve(s1, s2, i + 1, n);
        }

        int res = INT_MAX;

        for (int j = i + 1; j < n; j++)
        {
            if (s1[j] == s2[i])
            {
                swap(s1[j], s1[i]);
                res = min(res, solve(s1, s2, i + 1, n) + 1);
                swap(s1[j], s1[i]);
            }
        }
        return res;
    }
    int kSimilarity(string s1, string s2)
    {
        int n = s1.size();

        return solve(s1, s2, 0, n);
    }
};
