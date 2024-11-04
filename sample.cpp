#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;

        while (!q.empty())
        {
            int sz = q.size();
            steps++;
            for (int i = 0; i < sz; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (auto d : dir)
                {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.')
                    {
                        if (nx == 0 || ny == 0 || nx == n - 1 || ny == m - 1)
                        {
                            return steps;
                        }

                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }

            }
        }

        return -1;
    }
};
