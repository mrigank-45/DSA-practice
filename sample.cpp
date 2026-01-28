#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int countK = count(nums.begin(), nums.end(), k);
        int maxIncrease = 0;

        for (int i = 1; i <= 50; i++) {
            if (i == k) continue;

            int delta = k - i;
            int balance = 0, peak = 0;

            for (int j = 0; j < nums.size(); j++) {
                balance += (nums[j] == i) ? 1 : (nums[j] == k) ? -1 : 0;
                if (balance < 0) balance = 0;
                peak = max(peak, balance);
            }

            maxIncrease = max(maxIncrease, peak);
        }

        return countK + maxIncrease;
    }
};