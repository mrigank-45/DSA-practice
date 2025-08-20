#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int n = board.size();
        int m = board[0].size();
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        queue<pair<int, int>> q;
        q.push({click[0], click[1]});
        unordered_set<string> visited;
        visited.insert(to_string(click[0]) + to_string(click[1]));
        bool flag = false;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if (board[x][y] == 'M')
                {
                    board[x][y] = 'X';
                    flag = true;
                    continue;
                }
                vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
                vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
                int count = 0;
                for (int i = 0; i < 8; i++)
                {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m)
                    {
                        if (board[newX][newY] == 'M')
                        {
                            count++;
                        }
                    }
                }
                if (count > 0)
                {
                    board[x][y] = count + '0';
                }
                else
                {
                    board[x][y] = 'B';
                    for (int i = 0; i < 8; i++)
                    {
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        if (newX >= 0 && newX < n && newY >= 0 && newY < m)
                        {
                            string pos = to_string(newX) + to_string(newY);
                            if (visited.find(pos) == visited.end())
                            {
                                visited.insert(pos);
                                q.push({newX, newY});
                            }
                        }
                    }
                }
            }
            if (flag)
            {
                break;
            }
        }

        return board;
    }
};
