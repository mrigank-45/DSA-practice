#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] <= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int main()
{
    vector<int> v = {7, 4, 5, 2, 6};
    vector<int> ans = nextGreaterElement(v, 5);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
