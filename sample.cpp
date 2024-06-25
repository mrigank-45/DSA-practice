#include <iostream>
#include <string>

using namespace std;

int findCoins(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += n / i;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << findCoins(n) << endl;

    return 0;
}
