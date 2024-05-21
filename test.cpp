#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> arr = {"54", "546", "548", "60"};
    sort(arr.begin(), arr.end(), [](string &a, string &b)
         { return a + b > b + a; });

         // print array
    for (string s : arr)
    {
        cout << s << " ";
    }

    return 0;
}
