#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(string word, int k)
    {
        int n = word.size();
        map<string, int> mp;
        int i = 0;

        while (i < n)
        {
            string s = "";
            for (int j = i; j < i + k; j++)
            {
                s += word[j];
            }
            mp[s]++;
            i += k;
        }
        int max = 0, cnt = 0;
        for (auto it : mp)
        {
            if (it.second > max)
            {
                max = it.second;
            }
            cnt += it.second;
        }

        return cnt - max;
    }
};
