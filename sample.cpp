#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        // min heap int,pair<int,int> to store distance and index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(int i=0; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            minHeap.push({dist, i});
        }

        vector<vector<int>> ans;

        while(k--){
            auto p = minHeap.top();
            minHeap.pop();
            ans.push_back(points[p.second]);
        }

        return ans;
        
    }
};
