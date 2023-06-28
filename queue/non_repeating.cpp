// Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to
// tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once,
// you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

// Input: A = "aabc" || Output: "a#bb"

#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    map<char, int> m;
    string ans = "";
    queue<char> q;

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        q.push(ch);
        m[ch]++;

        while (!q.empty() && m[q.front()] > 1)
        {
            q.pop();
        }
        if (!q.empty())
        {
            ans.push_back(q.front());
        }
        else
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{

    string A = "aabc";
    string ans = FirstNonRepeating(A);
    cout << ans << "\n";

    return 0;
}
