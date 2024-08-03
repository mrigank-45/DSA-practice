#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int n = word.size();
        vector<pair<int, int>> lower(26, {0, 0});
        vector<pair<int, int>> upper(26, {0, 0});

        for (int i = 0; i < n; i++)
        {
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                lower[word[i] - 'a'].first = 1;
                lower[word[i] - 'a'].second = i;
            }
            else
            {
                if (upper[word[i] - 'A'].first == 0)
                {
                    upper[word[i] - 'A'].first = 1;
                    upper[word[i] - 'A'].second = i;
                }
            }
        }
        int cnt = 0;

        for (int i = 0; i < 26; i++)
        {
            if (lower[i].first == 1 && upper[i].first == 1 && lower[i].second < upper[i].second)
            {
                cnt++;
            }
        }

        return cnt;
    }
};
