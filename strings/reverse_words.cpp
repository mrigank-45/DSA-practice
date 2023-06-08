// Input: i.like.this.program.very.much
// Output: much.very.program.this.like.i

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "i.like.this.program.very.much";
    vector<string> v;
    string temp;
    string ans;
    s.push_back('.');
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            v.push_back(temp);
            temp.clear();
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        ans = ans + v.back();
        ans.push_back('.');
        v.pop_back();
    }
    ans.pop_back();
    cout << ans << endl;
}
