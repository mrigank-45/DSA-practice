// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Input: n = 3 || Output: ["((()))","(()())","(())()","()(())","()()()"]

#include <bits/stdc++.h>
using namespace std;

void solve(string op, int open, int close)
{
    if (open == 0 && close == 0)
    {
        cout << op << endl;
        return;
    }
    // when count of open and close brackets are same then
    // we have only one choice to put open bracket
    if (open == close)
    {
        solve(op + '(', open - 1, close);
    }
    else if (open == 0)
    {
        // only choice is to put close brackets
        solve(op + ')', open, close - 1);
    }
    else if (close == 0)
    {
        // only choise is to use open bracket
        solve(op + '(', open - 1, close);
    }
    else
    {
        solve(op + '(', open - 1, close);
        solve(op + ')', open, close - 1);
    }
}
void generateParenthesis(int n)
{
    int open = n;
    int close = n;
    string op = "";
    solve(op, open, close);
}

int main()
{
    int n = 3;

    generateParenthesis(n);
}
