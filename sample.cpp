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
    int ans = 0;
    while (!pq.empty())
    {
        int val = pq.top();
        pq.pop();
        vector<int> temp;
        if (val - x > 0)
        {
            temp.push_back(val - x);
        }
        while (!pq.empty())
        {
            if (pq.top() - y > 0)
            {
                temp.push_back(pq.top() - y);
            }
            pq.pop();
        }
        for (int i = 0; i < temp.size(); i++)
        {
            pq.push(temp[i]);
        }

        ans++;
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
