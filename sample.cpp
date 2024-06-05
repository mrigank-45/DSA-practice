#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, int j, string path, vector<vector<char>> &mat, vector<vector<bool>> &vis, int n, int m)
    {
        path += mat[i][j];
        if (i == n - 1 && j == m - 1)
        {
            if (isPalindrome(path))
                return 1;
            else
                return 0;
        }
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
            return 0;
        int ans = 0;
        vis[i][j] = true;
        if (i + 1 < n)
            ans = (ans + solve(i + 1, j, path, mat, vis, n, m)) % mod;
        if (j + 1 < m)
            ans = (ans + solve(i, j + 1, path, mat, vis, n, m)) % mod;
        vis[i][j] = false;
        return ans % mod;
    }
    int countPalindromicPaths(vector<vector<char>> matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        return solve(0, 0, "", matrix, vis, n, m);
    }
};
