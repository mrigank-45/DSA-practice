#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int beautifulSubstrings(string s, int k)
    {
        int n = s.size();

        int cnt = 0;

        vector<int> prefix_constant(n + 1, 0);
        vector<int> prefix_vowel(n + 1, 0);

        int cnt_constant = 0;
        int cnt_vowel = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                cnt_vowel++;
            }
            else
            {
                cnt_constant++;
            }

            prefix_vowel[i + 1] = cnt_vowel;
            prefix_constant[i + 1] = cnt_constant;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cnt_v = prefix_vowel[j + 1] - prefix_vowel[i];
                int cnt_c = prefix_constant[j + 1] - prefix_constant[i];

                if ((cnt_v == cnt_c) && ((cnt_c * cnt_v) % k == 0))
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
