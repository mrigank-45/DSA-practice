#include <bits/stdc++.h>
using namespace std;

// a -> 1, b-> 10, c -> 100 and so on
// ac -> 101, bd -> 1010 and so on

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        vector<int> mask(n, 0);

        for (int i = 0; i < n; ++i)
        {
            int temp = 0;
            for (int j = 0; j < words[i].size(); ++j)
            {
                temp |= 1 << (words[i][j] - 'a');
            }
            mask[i] = temp;
        }

        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((mask[i] & mask[j]) == 0)
                {
                    int prod = words[i].size() * words[j].size();
                    res = max(res, prod);
                }
            }
        }

        return res;
    }
};
