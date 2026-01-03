#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>> mp;
        for(int i =0; i<n;i++){
            mp[edges[i]].push_back(i);
        }
        long long max_score = 0;
        int ans = 0;
        for(auto it: mp){
            long long score = 0;
            for(int i = 0; i<it.second.size();i++){
                score += it.second[i];
            }
            if(score>max_score){
                max_score = score;
                ans = it.first;
            }
            if(score==max_score && it.first<ans){
                ans = it.first;
            }
        }
        return ans;
    }
};
