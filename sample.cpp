#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int x, int y)
{
    int n = arr.size();
    sort(arr.rbegin(), arr.rend());
    int ans = 0;

    while (!arr.empty())
    {
        ans++;
        int val = arr[0];
        arr.erase(arr.begin());

        vector<int> temp;
        if (val - x > 0)
        {
            temp.push_back(val - x);
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] - y > 0)
            {
                temp.push_back(arr[i] - y);
            }
        }
        arr = temp;
    }
    return ans;
}

int main()
{
    vector<int> executionTime = {3, 4, 1, 7, 6};
    int x = 4;
    int y = 2;
    cout << solve(executionTime, x, y) << endl;
}
