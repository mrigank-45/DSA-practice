// Make Lexicographically Smallest Array by Swapping Elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define F first
    #define S second
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> sorted;
        
        for(int i=0;i<nums.size();i++){
            sorted.push_back({nums[i], i});
        }
        sort(sorted.begin(),sorted.end());
        
        
        vector<vector<pair<int,int>>> groups;
        
        groups.push_back({sorted[0]});
        
        for(int i=1;i<sorted.size();i++){
            if(sorted[i].F - sorted[i-1].F <= limit){
                groups.back().push_back(sorted[i]);
            }
            else
                groups.push_back({sorted[i]});
        }
        
        
        vector<int> ans(nums.size());
        
        
        for(auto group:groups){
            vector<int> indices;
            
            for(auto element: group){
                indices.push_back(element.S);
            }
            sort(indices.begin(),indices.end());
            
            for(int i=0;i<group.size();i++){
                ans[indices[i]] = group[i].F;
            }
            
        }
        return ans;
        
        
    }
};
