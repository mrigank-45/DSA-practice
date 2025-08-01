#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int n = 0, m = 0;
        for (auto &e : edges1)
        {
            n = max(n, max(e[0], e[1]));
        }
        n++;

        for (auto &e : edges2)
        {
            m = max(m, max(e[0], e[1]));
        }
        m++;

        vector<vector<int>> adjList1(n), adjList2(m);

        for (auto &e : edges1)
        {
            adjList1[e[0]].push_back(e[1]);
            adjList1[e[1]].push_back(e[0]);
        }

        for (auto &e : edges2)
        {
            adjList2[e[0]].push_back(e[1]);
            adjList2[e[1]].push_back(e[0]);
        }

        vector<int> path1(n);
        for (int i = 0; i < n; ++i)
        {
            path1[i] = bfs(i, adjList1, k);
        }

        int maxFound = 0;
        if (k > 0)
        {
            for (int i = 0; i < m; ++i)
            {
                int count = bfs(i, adjList2, k - 1);
                maxFound = max(maxFound, count);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            path1[i] += maxFound;
        }

        return path1;
    }

private:
    int bfs(int start, vector<vector<int>> &adjList, int k)
    {
        if (k == 0)
            return 1;

        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        int level = 0, nodesReached = 1;

        while (!q.empty() && level < k)
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                int node = q.front();
                q.pop();
                for (int neighbor : adjList[node])
                {
                    if (visited.count(neighbor) == 0)
                    {
                        visited.insert(neighbor);
                        q.push(neighbor);
                        ++nodesReached;
                    }
                }
            }
            ++level;
        }

        return nodesReached;
    }
};
