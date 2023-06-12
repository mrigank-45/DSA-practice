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

    long long int k = 2;

    for (long long int i = 0; i < s.size(); i++)
    {
        long long int count;

        while (count<=k)
        {
            
        }
        
    }
    
}
