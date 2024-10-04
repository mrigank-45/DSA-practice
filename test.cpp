#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<int> lastSeen(n, -1);
        vector<int> res;

        for (int i = m - 1, j = n - 1; i >= 0; i--)
        {
            if (j >= 0 && word1[i] == word2[j])
            {
                lastSeen[j] = i;
                j--;
            }
        }

        int matchPos = 0, coin = 0;
        for (int i = 0; i < m; i++)
        {
            if (matchPos < n)
            {
                bool letterMatch = word1[i] == word2[matchPos];
                if (letterMatch || (!coin && (matchPos == n - 1 || (i + 1 <= lastSeen[matchPos + 1]))))
                {
                    if (!letterMatch)
                        coin = 1;
                    res.push_back(i);
                    matchPos++;
                }
            }
        }
        // print the result 
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }

        return matchPos == n ? res : vector<int>();
    }
};
