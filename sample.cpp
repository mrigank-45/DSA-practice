#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> deg;
        for(int i =0; i<roads.size();i++){
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
        }
        vector<pair<int,int>> v;
        for(auto it : deg){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        unordered_map<int,int> mp;
        int curr = n;

        for(int i =0; i<v.size(); i++){
            mp[v[i].second] = curr;
            curr--;
        }
        long long ans = 0;
        for(int i =0; i<roads.size();i++){
            ans += mp[roads[i][0]];
            ans += mp[roads[i][1]];
        }
        return ans;

    }
};
