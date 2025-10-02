#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct hash_pair
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int n = target[0], m = target[1];
        unordered_set<pair<int, int>, hash_pair> st2;
        unordered_set<pair<int, int>, hash_pair> st;
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;
        q1.push({0, 0});

        for (auto &it : ghosts)
        {
            st.insert({it[0], it[1]});
            q2.push({it[0], it[1]});
        }

        st2.insert({0, 0});
        while (!q1.empty())
        {
            int size = q2.size();
            while (size--)
            {
                auto it = q2.front();
                q2.pop();
                vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (auto &d : dir)
                {
                    int x = it.first + d.first;
                    int y = it.second + d.second;
                    if (x < 0 || y < 0 || x > n || y > m)
                        continue;
                    if(x == n && y == m) return false;
                    st.insert({x, y});
                    q2.push({x, y});
                }
            }
            size = q1.size();
            while (size--)
            {
                auto it = q1.front();
                q1.pop();
                if (st.find(it) != st.end())
                {
                    continue;
                }
                if (it.first == n && it.second == m)
                    return true;
                vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (auto &d : dir)
                {
                    int x = it.first + d.first;
                    int y = it.second + d.second;
                    if (x < 0 || y < 0 || x > n || y > m)
                        continue;
                    q1.push({x, y});
                    st2.insert({x, y});
                }
            }
            
        }
        return false;
    }
};
