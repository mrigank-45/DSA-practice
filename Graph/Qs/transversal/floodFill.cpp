// Flood fill leetcode

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int finalColor)
    {
        int m = image.size();
        int n = image[0].size();

        bool flag = 0;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        int color = image[sr][sc];
        if (color == finalColor)
        {
            return image;
        }
        image[sr][sc] = finalColor;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty())
        {
            int k = q.size();
            while (k--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    {
                        continue;
                    }
                    if (image[nx][ny] == color)
                    {
                        image[nx][ny] = finalColor;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return image;
    }
};
