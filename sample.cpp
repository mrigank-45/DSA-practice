#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long res = 0;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            int curr = nums[i] - target[i];

            if (curr > 0 && prev < 0 || curr < 0 && prev > 0) {
                res += abs(curr);
            }
            else if (abs(curr) - abs(prev) > 0) {
                res += abs(curr - prev);
            }

            prev = curr;
        }

        return res;
    }
};
