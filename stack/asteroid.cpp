// We are given an array asteroids of integers representing asteroids in a row.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative
// meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same
// size, both will explode. Two asteroids moving in the same direction will never meet.

// Input: asteroids = [5,10,-5] || Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> v)
{
    stack<int> s;
    s.push(0);
    vector<int> temp;

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
    while (s.top() != 0)
    {
        temp.push_back(s.top());
        s.pop();
    }

    return temp;
}

int main()
{
    vector<int> v = {-1, 5, -2, 10, -5, -20};
    vector<int> ans = asteroidCollision(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
