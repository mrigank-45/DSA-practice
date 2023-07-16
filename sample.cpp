#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int> &hand, int groupSize)
{

    map<int, int> m;
    for (int i = 0; i < hand.size(); i++)
    {
        m[hand[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        h;

    for (auto it : m)
    {
        h.push({it.first, it.second});
    }

    while (!h.empty())
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < groupSize; i++)
        {
            if (h.empty())
            {
                return false;
            }
            else
            {
                v.push_back(h.top());
                h.pop();
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            h.push(v[i]);
        }
    }
    return true;
}

int main()
{
    vector<int> v = {1,2,3,6,2,3,4,7,8};
    bool ans = isNStraightHand(v,3);
    cout<<ans<<endl;
    return 0;
}
