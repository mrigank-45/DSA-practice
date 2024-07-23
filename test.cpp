#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;

    mp["b"] = 1;
    mp["a"] = 2;

    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}
