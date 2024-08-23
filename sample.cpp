#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compressedString(string word)
    {
        int n = word.size();
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            int count = 1;
            while (i < n - 1 && word[i] == word[i + 1] && count < 9)
            {
                count++;
                i++;
            }
            ans += to_string(count) + word[i];
        }
        return ans;
    }
};
