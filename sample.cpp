#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();
        int s = 0, i = 1, l = 1, color = colors[0], ans = 0;

        while (s < n)
        {
            if (colors[i%n] != color)
            {
                l++;
                if (l == k)
                {
                    ans++;
                    s++;
                    l--;
                    if (s == n)
                    {
                        break;
                    }
                }
            }
            else
            {
                s = i;
                l = 1;
                if (s == n)
                {
                    break;
                }
            }

            color = colors[i%n];
            i++;
        }

        return ans;
    }
};
