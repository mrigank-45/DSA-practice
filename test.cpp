#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "cabbacabbadc";
    int n = s.size();

    int i = 1, j = 0;
    vector<int> lps(n, 0);
    while (i < n)
    {
        if (s[i] == s[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j > 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] == 0;
                i++;
            }
        }
    }
    for (int i = 0; i < lps.size(); i++)
    {
        cout<<lps[i]<<" ";
    }
    cout<<endl<<lps[n-1];
}
