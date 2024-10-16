#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void SortedStack ::sort()
{
    stack<int> temp;
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        while (!temp.empty() && temp.top() > x)
        {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(x);
    }
    s = temp;
}
