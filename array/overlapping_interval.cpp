// Input: Intervals = {{1,3},{2,4},{6,8},{9,10}}
// Output: {{1, 4}, {6, 8}, {9, 10}}
// Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping intervals here,[1,3] and [2,4]. 
// Therefore we will merge these two and return [1,4],[6,8], [9,10].

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> v = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    vector<vector<int>> ans;

    int n = v.size();

    sort(v.begin(), v.end());

    ans.push_back({v[0][0], v[0][1]});

    for (int i = 1; i < n; i++)
    {
        if (ans.back()[1] >= v[i][0])
        {
            pair<int, int> temp = {ans.back()[0], ans.back()[1]};
            ans.pop_back();

            ans.push_back({temp.first, max(temp.second, v[i][1])});
        }
        else
        {
            ans.push_back({v[i][0], v[i][1]});
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i][0] << ans[i][1] << " ";
    }
}
