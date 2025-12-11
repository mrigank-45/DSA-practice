// Rat and maze problem

#include <bits/stdc++.h>
using namespace std;

void solve(int row, int col, vector<string> &ans, string path, vector<vector<int>> &vis, int n, vector<vector<int>> &m)
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // move down
    if (row + 1 < n && !vis[row + 1][col] && m[row + 1][col] == 1)
    {
        vis[row][col] = 1;
        path.push_back('D');
        solve(row + 1, col, ans, path, vis, n, m);
        vis[row][col] = 0;
        path.pop_back();
    }
    // left 
    if (col - 1 >= 0 && !vis[row][col - 1] && m[row][col - 1] == 1)
    {
        vis[row][col] = 1;
        path.push_back('L');
        solve(row, col - 1, ans, path, vis, n, m);
        vis[row][col] = 0;
        path.pop_back();
    }
    // right 
    if (col + 1 < n && !vis[row][col + 1] && m[row][col + 1] == 1)
    {
        vis[row][col] = 1;
        path.push_back('R');
        solve(row, col + 1, ans, path, vis, n, m);
        vis[row][col] = 0;
        path.pop_back();
    }
    // upward 
    if (row - 1 >= 0 && !vis[row - 1][col] && m[row - 1][col] == 1)
    {
        vis[row][col] = 1;
        path.push_back('U');
        solve(row - 1, col, ans, path, vis, n, m);
        vis[row][col] = 0;
        path.pop_back();
    }
}

vector<string> findPath(vector<vector<int>> m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    string path = "";
    if (m[0][0] == 1)
        solve(0, 0, ans, path, vis, n, m);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    vector<string> s = findPath(m, n);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << endl;
    }

    return 0;
}
