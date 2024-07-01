#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<char>> &arr, int queries)
    {
        unordered_map<char, vector<char>> mp;

        for (int i = 0; i < arr.size(); i++)
        {
            char lesser, greater;
            if (arr[i][1] == '>')
            {
                greater = arr[i][0];
                lesser = arr[i][2];
            }
            else
            {
                greater = arr[i][2];
                lesser = arr[i][0];
            }
            mp[greater].push_back(lesser);
            if (mp[lesser].size() > 1)
            {
                for (auto it : mp[lesser])
                {
                    mp[greater].push_back(it);
                }
            }
        }

        for (int i = 0; i < queries; i++)
        {
            char a, b;
            cin >> a >> b;
            if (find(mp[a].begin(), mp[a].end(), b) != mp[a].end())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

        }
    }
};
