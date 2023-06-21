// C++ program to demonstrate functioning of substr()
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Take any string
    string s1 = "Geeks";

    // Copy two characters of s1 (starting
    // from position 3)
    string a = s1.substr(0, 3);
    string b = s1.substr(3, s1.size() - 3);

    // cout << a << endl;
    // cout << b << endl;

    vector<string> ss;
    ss.pop_back();
    cout<<ss.size();

    return 0;
}
