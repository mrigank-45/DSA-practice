#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr)
{
    int n = arr.size();
    if (n < 3)
    {
        return 0;
    }
    vector<int> prefix(n, 0);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    map<int, vector<int>> mp;
    mp[arr[0]].push_back(0);
    mp[arr[1]].push_back(1);
    int cnt = 0;

    for (int i = 2; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            for (auto index : mp[arr[i]])
            {
                if ((i - index >= 2) && ((prefix[i] - prefix[index] - arr[i]) == arr[i]))
                {
                    cnt++;
                }
            }
        }

        mp[arr[i]].push_back(i);
    }
    return cnt;
}
int main()
{
    vector<int> capacity = {6, 1, 2, 3, 6};
    cout << solve(capacity) << endl;
}
