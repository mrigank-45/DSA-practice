#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;

    long long dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return INT_MAX;

        long long count = grid[i][j];
        grid[i][j] = 0;

        int x = dfs(i+1, j, grid);
        int y = dfs(i, j+1, grid);
        int a = dfs(i-1, j, grid);
        int b = dfs(i, j-1, grid);

        if (x != INT_MAX) count += x;
        if (y != INT_MAX) count += y;
        if (a != INT_MAX) count += a;
        if (b != INT_MAX) count += b;

        return count;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    long long curr = dfs(i, j, grid);
                    if (curr % k == 0) ans++;
                }
            }
        }
        return ans;
    }
};
