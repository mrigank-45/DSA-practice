#include <bits/stdc++.h>
using namespace std;

map<int, int> solve(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    s.push(INT_MAX);
    map<int, int> m;

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() <= curr)
        {
            s.pop();
        }
        // ans is stack ka top

        if (s.top() == INT_MAX)
        {
            m.insert({arr[i],-1});
        }
        else
        {
            m.insert({arr[i],s.top()});
        }

        s.push(curr);
    }
    return m;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    map<int, int> m = solve(nums2);
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(m[nums1[i]]);
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 3, 4, 2};
    vector<int> v1 = {3, 4, 2};
    vector<int> ans = nextGreaterElement(v1,v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
