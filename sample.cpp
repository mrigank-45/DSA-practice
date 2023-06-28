#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> v, int k)
{
    deque<int> dq;
    vector<int> ans;
    int index = 0;

    for (int i = 0; i < k; i++)
    {
        if (v[i] >= v[index])
        {
            index = i;
        }
    }
    dq.push_back(index);

    ans.push_back(v[dq.front()]);

    for (int i = k; i < v.size(); i++)
    {

        if (!dq.empty() && (i - dq.front()) >= k)
        {
            dq.pop_front();
        }

        if (!dq.empty() && v[i] >= v[dq.front()])
        {
            dq.pop_back();
            dq.push_back(i);
        }
        else if (dq.empty())
        {
            dq.push_back(i);
        }

        ans.push_back(v[dq.front()]);
    }
    return ans;
}

int main()
{

    vector<int> v = {1, 3, 1, 2, 0, 5};
    int k = 3;

    vector<int> ans = maxSlidingWindow(v, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
