#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        int startX = KnightPos[0] - 1;
        int startY = KnightPos[1] - 1;
        int endX = TargetPos[0] - 1;
        int endY = TargetPos[1] - 1;

        vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
        vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({startX, startY});
        visited[startX][startY] = true;

        int steps = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int k = 0; k < size; k++)
            {
                auto temp = q.front();
                int x = temp.first;
                int y = temp.second;
                q.pop();

                if (x == endX && y == endY)
                {
                    return steps;
                }

                for (int i = 0; i < 8; i++)
                {
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if (newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY])
                    {
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
