#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, ct = 0;
        cin >> n;
        vector<pair<long long int, long long int>> v;
        vector<long long int> a;
        v.push_back({0, 0});
        for (long long int i = 1; i <= n; i++)
        {
            long long int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        for (long long int i = 1; i <= n; i++)
        {
            long long int k = 0;
            for (long long int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    if ((i < v[j].first) || (i > v[j].second))
                    {
                        k++;
                        break;
                    }
                }
            }
            if ((k == 0) && ((i < v[i].first) || (i > v[i].second)))
            {
                ct++;
                a.push_back(i);
            }
        }
        sort(a.begin(), a.end());
        cout << ct << endl;
        for (long long int i = 0; i < a.size(); i++)
        {
            cout << a[i] << endl;
        }
    }
    return 0;
}
