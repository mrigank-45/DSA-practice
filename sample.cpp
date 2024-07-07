#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<vector<int>> &image, int i, int j, int n, int m, int threshold)
    {
        if (i < 0 || j < 0 || i >= n - 2 || j >= m - 2)
        {
            return false;
        }
        if (abs(image[i][j] - image[i][j + 1]) > threshold || abs(image[i][j] - image[i + 1][j]) > threshold)
        {
            return false;
        }
        int i1 = i + 1, j1 = j;
        int i2 = i, j2 = j + 1;
        int i3 = i + 1, j3 = j + 1;
        if (abs(image[i1][j1] - image[i1][j1 + 1]) > threshold || abs(image[i1][j1] - image[i1 + 1][j1]) > threshold)
        {
            return false;
        }
        if (abs(image[i2][j2] - image[i2][j2 + 1]) > threshold || abs(image[i2][j2] - image[i2 + 1][j2]) > threshold)
        {
            return false;
        }
        if (abs(image[i3][j3] - image[i3][j3 + 1]) > threshold || abs(image[i3][j3] - image[i3 + 1][j3]) > threshold)
        {
            return false;
        }
        i3++;
        j3++;
        if (abs(image[i3][j3] - image[i3][j3 - 1]) > threshold || abs(image[i3][j3] - image[i3 - 1][j3]) > threshold)
        {
            return false;
        }
        int i4 = i3 - 1, j4 = j3;
        int i5 = i3, j5 = j3 - 1;
        if(abs(image[i4][j4] - image[i4][j4 - 1]) > threshold || abs(image[i4][j4] - image[i4 - 1][j4]) > threshold)
        {
            return false;
        }
        if(abs(image[i5][j5] - image[i5][j5 - 1]) > threshold || abs(image[i5][j5] - image[i5 - 1][j5]) > threshold)
        {
            return false;
        }

        return true;
    }
    void helper(vector<vector<int>> &image, map<pair<int, int>, vector<int>> &mp, int i, int j, int threshold)
    {
        int sum = 0;
        for (int x = i; x < i + 3; x++)
        {
            for (int y = j; y < j + 3; y++)
            {
                sum += image[x][y];
            }
        }
        int avg = sum/9;
        for (int x = i; x < i + 3; x++)
        {
            for (int y = j; y < j + 3; y++)
            {
                mp[{x, y}].push_back(avg);
            }
        }
    }
    
    vector<vector<int>> resultGrid(vector<vector<int>> &image, int threshold)
    {
        int n = image.size();
        int m = image[0].size();
        map<pair<int, int>, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (check(image, i, j, n, m, threshold))
                {
                    helper(image, mp, i, j, threshold);
                }
            }
        }
        vector<vector<int>> result = image;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mp.find({i, j}) != mp.end())
                {
                    int l = mp[{i, j}].size();
                    int sum = accumulate(mp[{i, j}].begin(), mp[{i, j}].end(), 0);
                    int val = sum/l;
                    result[i][j] = val;
                }
            }
        }

        return result;
    }
};
