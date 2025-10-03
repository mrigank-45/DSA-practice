#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<long long, long long> mp; 

        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = 0; j < wall[i].size() - 1; j++) {
                sum += wall[i][j];
                mp[sum]++;
            }
        }

        long long maxEdges = 0;
        for(auto it : mp) {
            maxEdges = max(maxEdges, it.second);
        }

        return n - maxEdges;
        
    }
};
