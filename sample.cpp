#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestCommonPrefix(vector<string> &words)
    {
        int n = words.size();
        if (n == 1)
            return {0};

        vector<int> maxPrefix(n, 0);
        int minLength = INT_MAX;
        maxPrefix[0] = 0;
        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            int j = 0;
            while (j < words[i - 1].size() && j < words[i].size() && words[i - 1][j] == words[i][j])
            {
                j++;
            }
            maxi = max(maxi, j);
            maxPrefix[i] = maxi;
        }

        vector<int> maxSuffix(n, 0);
        maxSuffix[n - 1] = 0;
        maxi = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int j = 0;
            while (j < words[i + 1].size() && j < words[i].size() && words[i + 1][j] == words[i][j])
            {
                j++;
            }
            maxi = max(maxi, j);
            maxSuffix[i] = maxi;
        }

        // print maxPrefix and maxSuffix for debugging
        for(int i = 0; i < n; i++)
        {
            cout << "maxPrefix[" << i << "] = " << maxPrefix[i] << ", maxSuffix[" << i << "] = " << maxSuffix[i] << endl;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans.push_back(maxSuffix[i + 1]);
            }
            else if (i == n - 1)
            {
                ans.push_back(maxPrefix[i - 1]);
            }
            else
            {
                int j = 0;
                while (j < words[i - 1].size() && j < words[i + 1].size() && words[i - 1][j] == words[i + 1][j])
                {
                    j++;
                }
                ans.push_back(max(j, max(maxPrefix[i - 1], maxSuffix[i + 1])));
            }
        }
        return ans;
    }
};
