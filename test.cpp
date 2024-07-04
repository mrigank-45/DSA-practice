#include <bits/stdc++.h>
using namespace std;

int main()
{
     map<int, int> mp;
     mp[2] = 5;
     mp[8] = 7;
     mp[3] = 1;

     for (auto it : mp)
     {
          cout << it.first << ": " << it.second << endl;
     }

     return 0;
}
