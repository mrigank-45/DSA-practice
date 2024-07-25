#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> z_fn(const string &s)
    {
        int n = s.size(), l = 0, r = 0;
        vector<int> z(n);
        for (int i = 1; i < n; i++)
        {
            if (i > r)
            {
                l = r = i;
                while (r < n && s[r] == s[r - l])
                    r++;
                z[i] = r - l;
                r--;
            }
            else
            {
                int cur = i - l;
                if (z[cur] + i < r + 1)
                    z[i] = z[cur];
                else
                {
                    l = i;
                    while (r < n && s[r] == s[r - l])
                        r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }

    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        vector<int> ans;

        for (auto &query : wordsQuery)
        {
            int index = 0;
            int maxLen = 0;
            reverse(query.begin(), query.end());

            for (int i = 0; i < wordsContainer.size(); i++)
            {
                string container = wordsContainer[i];
                reverse(container.begin(), container.end());
                string temp = container + "#" + query;
                vector<int> arr = z_fn(temp);
                int length = arr[container.size() + 1];

                if (length > maxLen)
                {
                    maxLen = length;
                    index = i;
                }
                else if (length == maxLen && wordsContainer[i].size() < wordsContainer[index].size())
                {
                    index = i;
                }
            }

            ans.push_back(index);
        }

        return ans;
    }
};
