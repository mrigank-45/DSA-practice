// Asteroid Collision | Leetcode

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> v)
{
    stack<int> s;
    s.push(0);

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] < 0)
        {
            s.push(v[i]);
        }
        else
        {
            bool toPush = true;
            while (s.top() < 0)
            {
                if (v[i] > abs(s.top()))
                {
                    s.pop();
                }
                else if (v[i] == abs(s.top()))
                {
                    s.pop();
                    toPush = false;
                }
                else
                {
                    toPush = false;
                    break;
                }
            }
            if (toPush)
            {
                s.push(v[i]);
            }
        }
    }

    vector<int> temp;

    while (s.top() != 0)
    {
        temp.push_back(s.top());
        s.pop();
    }

    return temp;
}
