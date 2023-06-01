#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {
        6,
        -2,
        -5,
        7,
        -9,
    };

    int n = v.size();
    int x = 3;

    int a = v[0];
    int b = v[1];
    int c = v[2];

    int diff = abs(x - (a + b + c));
    int sum = a + b + c;

    for (int i = 3; i < n; i++)
    {
        if (abs(x - (v[i] + b + c)) < diff)
        {
            diff = abs(x - (v[i] + b + c));
            sum = v[i] + b + c;
            cout << 1 << endl;
            cout << i << endl;
        }
        if (abs(x - (v[i] + a + c)) < diff)
        {
            diff = abs(x - (v[i] + b + c));
            int sum = v[i] + a + c;
            cout << 2 << endl;
            cout << i << endl;
        }
        if (abs(x - (v[i] + b + a)) < diff)
        {
            diff = abs(x - (v[i] + b + c));
            int sum = v[i] + b + c;
            cout << 3 << endl;
            cout << i << endl;
        }
    }

    cout << sum << endl;
}
