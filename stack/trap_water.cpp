#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> v, int k)
{
    int n = v.size();
    pair<int, int> p;
    int max = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        if (v[i] >= max)
        {
            max = v[i];
            p.first = i;
            p.second = max;
        }
    }
    int r = k;
    while (r < n)
    {
        if (v[k] >= max)
        {
            max = v[k];
            p.first = k;
            p.second = max;
        }
    }
}

int main()
{
    vector<int> arr;
    int k = 3;
    arr = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = maxSlidingWindow(arr, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
