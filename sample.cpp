#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        int minReachable = n; 
        int bestCity = -1;

        for (int i = 0; i < n; i++) {
            
            vector<int> dist(n, INT_MAX);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;

                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        
                        if (dist[v] <= distanceThreshold) {
                            q.push(v);
                        }
                    }
                }
            }

            int count = 0;
            for (int d : dist) {
                if (d <= distanceThreshold && d > 0) {
                    count++;
                }
            }

            if (count <= minReachable) {
                minReachable = count;
                bestCity = i;
            }
        }

        return bestCity;
    }
};
