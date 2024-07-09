#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPSArray(string pattern)
{
    vector<int> lps(pattern.length(), 0);
    int len = 0;
    int i = 1;
    while (i < pattern.length())
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int KMPSearch(string text, string pattern)
{
    vector<int> lps = computeLPSArray(pattern);

    string temp = pattern + "#" + text;
    int n = temp.length();
    int m = pattern.length();
    int cnt = 0;

    for (int i = m; i < n; i++)
    {
        if (lps[i] == m)
            cnt++;
    }
    return cnt;
}

int main()
{
    string s1 = "abcdbc";
    string s2 = "bc";
    cout << KMPSearch(s1, s2) << endl;
}
