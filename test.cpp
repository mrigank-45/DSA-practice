#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        int n = s.length();
        string ans = "";

        // Initialize the result with numbers 1 to n+1
        for (int i = 0; i <= n; i++)
        {
            ans += to_string(i + 1);
        }

        // Traverse the pattern and reverse portions where there's a 'D' sequence
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
            {
                // Find the end of the current D-sequence
                int j = i;
                while (j < n && s[j] == 'D')
                {
                    j++;
                }
                // Reverse the segment corresponding to the D sequence
                reverse(ans.begin() + i, ans.begin() + j + 1);
                // Move i to the end of the D-sequence
                i = j - 1;
            }
        }

        return ans;
    }
};
