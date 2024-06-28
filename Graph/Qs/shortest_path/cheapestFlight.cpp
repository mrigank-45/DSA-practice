// Cheapest Flights Within K Stops
// ALGO: use dijkstra algo but we store the elements in terms of the minimum number of stops in the priority queue so that we can check in every itretion that ans is within limits.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Create a queue which stores the node and their distanceances from the source in the form of {stops, {node, distance}} with ‘stops’ indicating
        // the no. of nodes between src and current node.
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});

        vector<int> distance(n, 1e9);
        distance[src] = 0;

        // iterate through the graph using a queue like in Dijkstra with popping out the element with min stops first.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // We stop the process as soon as the limit for the stops reaches.
            if (stops > K)
                continue;
                
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int price = it.second;

                // We only update the queue if the new calculated distance is less than the prev and the stops are also within limits.
                if (cost + price < distance[adjNode])
                {
                    distance[adjNode] = cost + price;
                    q.push({stops + 1, {adjNode, cost + price}});
                }
            }
        }

        if (distance[dst] == 1e9)
            return -1;
        return distance[dst];
    }
};
