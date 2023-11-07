#include <bits/stdc++.h>
using namespace std;

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2)
        {
            return hash1 ^ hash2;
        }

        return hash1;
    }
};

bool check(unordered_map<pair<int, int>, bool, hash_pair> m_one)
{
    for (auto it : m_one)
    {
        if (it.second == true)
        {
            return true;
        }
    }
    return false;
}

void print(unordered_map<pair<int, int>, bool, hash_pair> m)
{
    for (auto it : m)
    {
        if (it.second)
        {
            cout << it.first.first << " " << it.first.second << " " << endl;
        }
    }
}

int minimumMoves(vector<vector<int>> &grid)
{

    unordered_map<pair<int, int>, bool, hash_pair> m_zero;
    unordered_map<pair<int, int>, bool, hash_pair> m_one;

    queue<pair<int, int>> q;

    int cnt = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m_zero[{i, j}] = false;
            m_one[{i, j}] = false;

            if (grid[i][j] == 0)
            {
                m_zero[{i, j}] = true;
            }
            else if (grid[i][j] > 1)
            {
                m_one[{i, j}] = true;
            }
        }
    }
    // print(m_zero);
    // print(m_one);

    if (!check(m_one))
    {
        return 0;
    }

    do
    {
        int min = INT_MAX;
        int q = 0, r = 0;
        int x, y;

        for (auto item : m_one)
        {
            if (item.second == true)
            {
                x = item.first.first;
                y = item.first.second;

                for (auto it : m_zero)
                {
                    if (it.second == true)
                    {
                        cout << "x: " << x << " y: " << y << endl;
                        cout << "m: " << it.first.first << " n: " << it.first.second << endl;
                        int a = abs(x - it.first.first) + abs(y - it.first.second);
                        cout << "a: " << a << endl;
                        if (a < min)
                        {
                            min = a;
                            q = it.first.first;
                            r = it.first.second;
                            // cout << "min: " << min << endl;
                        }
                    }
                }
            }
        }
        cout << "min1: " << min << endl;
        cout << "x1: " << x << " y2: " << y << endl;
        cout << "m1: " << q << " n1: " << r << endl;

        grid[x][y]--;
        // cout << "grid[x][y]: " << grid[x][y] << endl;
        if (grid[x][y] == 1)
        {
            m_one[{x, y}] = false;
        }

        grid[q][r]++;
        m_zero[{q, r}] = false;
        cnt += min;
    } while (check(m_one));

    return cnt;
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 0}, {1, 0, 0}, {1, 0, 3}};
    cout << "Minimum moves: " << minimumMoves(grid);
    return 0;
}
