// Minimum Array Changes to Make Differences Equal
// https://leetcode.com/problems/minimum-array-changes-to-make-differences-equal/solutions/5519547/c-prefix-sum-approach/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> diff(k+1);
        vector<int> allow(k+1); // largest allowed difference

        int n = nums.size();
        int p = n/2;
        
        for (int i = 0; i < p; ++i){
            //count diff;
            int d = abs(nums[i]- nums[n-i-1]);
            diff[d]++;
            //count largest allowed difference()
            int q = max(k-min(nums[i], nums[n-i-1]), max(nums[i], nums[n-i-1]));
            allow[q]++;
        }
        int res = p - diff[0] + 0; //everyone change to equal pairs
        int accu = 0;
        for (int i = 1; i < k+1; ++i){
            //prefix sum
            accu += allow[i-1];
            res = min(res, p -diff[i] + accu); 
        }
        return res;
    }
};
