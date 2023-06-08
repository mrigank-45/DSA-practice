#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
    if (S == P)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string s = "vnrtysfrzrmzlygfv";

    long long int max = 1;
    long long int index = 0;
    long long int n = s.size();

    for (long long int i = 0; i < s.size(); i++)
    {
        long long int k = n - i;
        while (k > 0)
        {
            if (isPalindrome(s.substr(i, k)))
            {
                if (k > max)
                {
                    max = k;
                    index = i;
                }
                else if (k == max)
                {
                    if (i < index)
                    {
                        max = k;
                        index = i;
                    }
                }
                break;
            }
            k--;
        }
    }
    string ans = s.substr(index, max);
    cout << ans << endl;
}
