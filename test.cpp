#include <bits/stdc++.h>
using namespace std;

void check(int n)
{
    int e = 0, o = 0;
    for (int i = 0; i < 32; i++)
    {
        if (n & (1 << i))
        {
            if (i % 2 == 0)
            {
                e++;
            }
            else
            {
                o++;
            }
        }
    }
    cout << e << " " << o << endl;
}

int main()
{
    int a;
    cin >> a;
    check(a);
    return 0;
}
