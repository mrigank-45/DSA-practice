#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string concatinate(string &a, string &b)
    {
        if (a[a.length() - 1] == b[0])
        {
            return a + b.substr(1, b.length() - 1);
        }
        else
        {
            return a + b;
        }
    }

    int solve(vector<string> &words, int index, string prev, vector<int> dp)
    {
        if (index == words.size())
        {
            return prev.length();
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }

        // Case 1
        string temp1 = concatinate(prev, words[index]);
        int ans1 = solve(words, index + 1, temp1, dp);

        // Case 2
        string temp2 = concatinate(words[index], prev);
        int ans2 = solve(words, index + 1, temp2, dp);

        return dp[index] = min(ans1, ans2);
    }

    int minimizeConcatenatedLength(vector<string> &words)
    {
        if (words.size() == 0)
        {
            return words[0].length();
        }

        vector<int> dp(words.size() + 1, -1);

        return solve(words, 1, words[0], dp);
    }
};
