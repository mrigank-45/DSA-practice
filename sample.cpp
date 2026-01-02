#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp; // sum before index -> index
        mp[0] = 0;
        int sum = 0, ans = 0, prev = -1;
        for(int i =0; i<n; i++){
            sum+= nums[i];
            if(mp.find(sum - target) != mp.end()){
                if(mp[sum-target]>prev){
                    ans++;
                    prev = i;
                }
            }
            mp[sum] = i + 1;
        }
        return ans;
        
    }
};
