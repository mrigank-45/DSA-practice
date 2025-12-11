#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int> nums, int l, int r, int sum1, int sum2, bool turn) {
        if (l > r) {
            return sum1 >= sum2;
        }
        if (turn) {
            return check(nums, l + 1, r, sum1 + nums[l], sum2, !turn) ||
                   check(nums, l, r - 1, sum1 + nums[r], sum2, !turn);
        } else {
            return check(nums, l + 1, r, sum1, sum2 + nums[l], !turn) &&
                   check(nums, l, r - 1, sum1, sum2 + nums[r], !turn);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return check(nums, 0, n - 1, 0, 0, true);
    }
};
