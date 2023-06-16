#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> v, int n, int h, int mid)
{
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % mid == 0)
        {
            time += v[i] / mid;
        }
        else
        {
            time = time + v[i] / mid + 1;
        }
        if (time > h)
        {
            return false;
        }
    }
    return true;
}

int Solve(vector<int> v, int n, int h)
{
    int s = 0;
    int e = *max_element(v.begin(), v.end());
    int ans = e;

    while (s <= e)
    {
        cout<<s<<' '<<e<<endl;
        int mid = s + (e - s) / 2;

        if (isPossible(v, n, h, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {3, 6, 7, 11};

    int ans = Solve(v, 4, 8);
    cout << ans << endl;
}
