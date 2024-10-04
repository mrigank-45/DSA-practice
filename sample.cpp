#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<int> res;

        for (int skip = 0; skip < m; skip++)
        {
            vector<int> ans;
            int i = 0, j = 0;
            while (i < n && j < m)
            {
                if (word1[i] == word2[j])
                {
                    ans.push_back(i);
                    i++;
                    j++;
                }
                else if (skip == j)
                {
                    ans.push_back(i);
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
            if (ans.size() == m)
            {
                if (res.size() == 0)
                {
                    res = ans;
                }
                else
                {
                    if (ans < res)
                    {
                        res = ans;
                    }
                }
            }
        }

        return res;
    }
};
