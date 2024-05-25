#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubstring(string S)
    {
        int a = 0, b = 0, c = 0;
        int i = 0;
        int j = 0;
        int n = S.size();
        int ans = INT_MAX;

        while (j < n)
        {
            if (S[j] == '0')
            {
                a++;
            }
            else if (S[j] == '1')
            {
                b++;
            }
            else if (S[j] == '2')
            {
                c++;
            }

            while (i < j)
            {
                if (S[i] == '0' && a > 1)
                {
                    a--;
                    i++;
                }
                else if (S[i] == '1' && b > 1)
                {
                    b--;
                    i++;
                }
                else if (S[i] == '2' && c > 1)
                {
                    c--;
                    i++;
                }
                else
                {
                    break;
                }
            }

            if (a >= 1 && b >= 1 && c >= 1)
            {
                ans = min(ans, j - i + 1);
            }
            j++;
        }

        if (ans == INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};
