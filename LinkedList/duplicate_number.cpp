// Find the Duplicate Number | Leetcode
// we have to solve it without modifing the array and without using extra space

// Approach: We treat the array as a linked list, where the index represents the node and the value at that index represents the next node.
// Then we simple have to find the entry point of the cycle in the linked list.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Find the intersection point of the two pointers
        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow != fast);

        // Find the entrance of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
