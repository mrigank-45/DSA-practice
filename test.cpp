#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool hasPath(vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> l;

        // Populate the adjacency list with edges
        for (const auto &edge : edges)
        {
            l[edge[0]].push_back(edge[1]);
            l[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> s;

        // Define DFS function
        function<bool(int)> dfs = [&](int node)
        {
            // If the current node is the destination, return true
            if (node == destination)
            {
                return true;
            }

            // Mark the current node as visited
            s.insert(node);

            // Check neighbors of the current node
            for (int j : l[node])
            {
                // If neighbor is not visited and DFS from neighbor is true
                if (s.find(j) == s.end() && dfs(j))
                {
                    return true;
                }
            }

            // If no path found from current node, return false
            return false;
        };

        // Start DFS from the source node
        return dfs(source);
    }
};
