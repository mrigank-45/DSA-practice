// for an array, return the next smaller element for rach item in the array

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main()
{
    vector<int> v = {2, 4, 3, 2};
    vector<int> ans = nextSmallerElement(v, 4);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
