#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int i = 0, j = 0;

        while (i < str1.size())
        {
            if (str1[i] == str2[j])
            {
                i++;
                j++;
            }
            else if ((str1[i] - 'a') + 1 == str2[j] - 'a')
            {
                i++;
                j++;
            }
            else if (str1[i] == 'z' &&  str2[j] == 'a')
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }

            if (j == str2.length())
            {
                return true;
            }
        }

        return false;
    }
};
