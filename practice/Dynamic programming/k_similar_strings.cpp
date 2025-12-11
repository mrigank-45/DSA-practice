// K-Similar Strings
// it is imp to note that we cannot make dp[i] for memo as we are swapping the strings and the strings are changing, hence dp[s1]
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, int> m;
    int helper(string &s1, string &s2, int index)
    {
        if (m.find(s1) != m.end())
        {
            return m[s1];
        }

        int ans = INT_MAX;

        while (s1[index] == s2[index])
        {
            index++;
        }
        for (int i = index + 1; i < s1.size(); i++)
        {
            if (s1[i] == s2[index])
            {
                swap(s1[i], s1[index]);
                ans = min(ans, 1 + helper(s1, s2, index + 1));
                swap(s1[i], s1[index]);
            }
        }

        return m[s1] = ans;
    }
    int kSimilarity(string s1, string s2)
    {
        m[s2] = 0;
        return helper(s1, s2, 0);
    }
};
