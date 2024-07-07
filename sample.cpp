#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTimeToInitialState(string word, int k)
    {
        int len = word.size();
        int ans = 1;
        int i = k;
        while (i<len)
        {
            if (word.substr(i, len - i) == word.substr(0, len - i))
            {
                break;
            }
            else
            {
                i += k;
                ans++;
            }
        }
        return ans;
    }
};
