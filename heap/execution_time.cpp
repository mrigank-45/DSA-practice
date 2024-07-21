#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int x, int y)
{
    int n = arr.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int ans = 0, decrement = 0;

    while (1)
    {
        int val = pq.top();
        pq.pop();
        if (val - decrement * y <= 0)
        {
            break;
        }
        else
        {
            pq.push(val - x + y);
            decrement++;
            ans++;
        }
    }
    return ans;
}
int main()
{
    vector<int> executionTime = {3, 3, 6, 3, 9};
    int x = 3;
    int y = 2;
    cout << solve(executionTime, x, y) << endl; // expected: 3
}
