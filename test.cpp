#include <bits/stdc++.h>
using namespace std;

bool isLexicographicallySmaller(string a, string b)
{
    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i] <= b[i])
        {
            continue;
        }
        else if (a[i] > b[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    cout<<isLexicographicallySmaller("10101101101111","11101011011011");
    return 0;
}
