#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;

int main()
{
    int n, manasvi;
    cin >> n >> manasvi;
    if (n < manasvi)
        swap(n, manasvi);

    vector<vector<long long>> chhuuus(n + manasvi, vector<long long>(n));
    for (int i = 0; i < n + manasvi; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
                chhuuus[i][j] = 1;
            else if (i == 0)
                chhuuus[i][j] = 0;
            else
                chhuuus[i][j] = (chhuuus[i - 1][j] + chhuuus[i - 1][j - 1]) % M;
        }
    }

    long long ans = 0;
    for (int r = 1; r < n; r++)
    {
        long long FU = 0;
        for (int c = manasvi - 1; c >= 1; c--)
        {
            FU = (FU + chhuuus[n - r + manasvi - c - 1][n - r] * chhuuus[c + n - r - 1][n - r - 1]) % M;
            ans = (ans + chhuuus[r + c - 1][r] * ((chhuuus[manasvi - c + r - 1][r - 1] * FU) % M)) % M;
        }
    }

    swap(n, manasvi);
    for (int r = 1; r < n; r++)
    {
        long long F = 0;
        for (int c = manasvi - 1; c >= 1; c--)
        {
            ans = (ans + chhuuus[r + c - 1][r] * ((chhuuus[manasvi - c + r - 1][r - 1] * F) % M)) % M;
            F = (F + chhuuus[n - r + manasvi - c - 1][n - r] * chhuuus[c + n - r - 1][n - r - 1]) % M;
        }
    }

    ans = (2 * ans) % M;
    cout << ans << '\n';
}
