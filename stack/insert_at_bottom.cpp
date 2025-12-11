// insert an element at bottom of stack using recursion and without using extra space

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int x)
{
    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}

int main()
{
    stack<int> s;
    s.push(2);

    pushAtBottom(s, 4);
    return 0;
}
