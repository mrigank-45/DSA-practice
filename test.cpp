#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Create an unordered map to store the count of visited nodes for each node.
    unordered_map<int, int> mp;

    // Depth-First Search (DFS) function to count visited nodes and detect loops.
    int dfs(vector<vector<int>> &graph, int src, int &loopEnd)
    {
        // Check if we've visited this node before.
        if (mp.find(src) != mp.end())
        {
            loopEnd = src;  // Mark the loop end if we encounter a previously visited node.
            return mp[src]; // Return the count of visited nodes from this node.
        }

        mp[src] = 0;   // Mark the current node as visited.
        int count = 1; // Initialize the count of visited nodes from this node to 1.

        // Recursively traverse all neighbors of the current node.
        for (auto x : graph[src])
        {
            count += dfs(graph, x, loopEnd); // Update the count by recursively visiting neighbors.
        }

        mp[src] = count; // Update the count of visited nodes for the current node.

        // If we have detected a loop, update the counts for all nodes in the loop.
        if (src == loopEnd)
        {
            int s = src;
            do
            {
                mp[s] = count;   // Set the count for nodes in the loop.
                s = graph[s][0]; // Move to the next node in the loop.
            } while (s != loopEnd);
        }

        return count; // Return the total count of visited nodes from this node.
    }

    // Main function to count visited nodes for each node in the given graph.
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        int n = edges.size();
        vector<vector<int>> graph(n);

        // Create the graph using the given edges.
        for (int i = 0; i < n; i++)
        {
            graph[i].push_back(edges[i]);
        }

        vector<int> ans;

        // Iterate through all nodes and count visited nodes for each node.
        for (int i = 0; i < n; i++)
        {
            if (mp.find(i) != mp.end())
            {
                ans.push_back(mp[i]); // If already computed, push the count to the answer.
                continue;
            }

            int loopEnd = -1;                   // Initialize the loopEnd variable to -1.
            int count = dfs(graph, i, loopEnd); // Count visited nodes starting from this node.
            ans.push_back(count);               // Push the count to the answer vector.
        }

        return ans; // Return the vector containing counts of visited nodes for each node.
    }
};
