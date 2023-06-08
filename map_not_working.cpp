// Given a string s, sort it in decreasing order based on the frequency of the characters. 
// Input: s = "tree"
// Output: "eert"

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "tree";

    map<char, int> m;
    map<int, char> m1;
    string ans;

    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) == m.end())
        {
            m[s[i]] = 1;
        }
        else
        {
            m[s[i]]++;
        }
    }

    for (auto item : m)
    {
        cout << item.first << " " << item.second << endl;
        m1[item.second] = item.first;
        cout<<m1[item.second]<<endl;
    }
    cout<<"gg"<<endl;
    for (auto item : m1)
    {
        cout << item.first << " " << item.second << endl;
    }
    for (auto item : m1)
    {
        for (int i = 0; i < item.first; i++)
        {
            ans.push_back(item.second);
            // cout << item.second << " ";
        }
        // cout << endl;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
