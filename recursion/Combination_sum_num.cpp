// Find all valid combinations of k numbers that sum up to n such that the following conditions are true: Only numbers 1 through 9 are used, Each
// number is used at most once. Return a list of all possible valid combinations. The list must not contain the same combination twice, and
// the combinations may be returned in any order.

// Input: k = 3, n = 9 || Output: [[1,2,6],[1,3,5],[2,3,4]]

#include <bits/stdc++.h>
using namespace std;

bool ispresent(int val, vector<int> visited)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == val)
        {
            return true;
        }
    }
    return false;
}

void solve(int k, int n, vector<int> output, vector<int> visited, int index, int sum, vector<vector<int>> &ans)
{
    // base case
    if (index >= k)
    {
        if (sum == n)
        {
            ans.push_back(output);
            return;
        }
        else
        {
            return;
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        if (!ispresent(i, visited))
        {
            sum += i;
            output.push_back(i);
            visited.push_back(i);
            solve(k, n, output, visited, index + 1, sum, ans);
            output.pop_back();
            sum -= i;
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{

    vector<vector<int>> ans;
    vector<int> output;
    vector<int> visited;
    int index = 0;
    int sum = 0;
    solve(k, n, output, visited, index, sum, ans);
    return ans;
}

int main()
{

    vector<vector<int>> s = combinationSum3(3, 7);
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}
