#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPick(vector<int>& nums, int k, int limit) {
        int count = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] <= limit) {
                count++;
                i += 2; 
            } else {
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPick(nums, k, mid)) {
                ans = mid;       
                high = mid - 1;
            } else {
                low = mid + 1;    
            }
        }
        return ans;
    }
};
