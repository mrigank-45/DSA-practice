#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Min-heap to store pairs, where each element is a tuple (sum, i, j)
        // sum = nums1[i] + nums2[j], i is index from nums1, j is index from nums2
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        
        vector<vector<int>> result;
        
        // If either nums1 or nums2 is empty, return an empty result
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // Initialize the heap with pairs from the first element in nums1 and every element in nums2
        // Only take up to k elements
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        // Extract the smallest k pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();  // Get the smallest sum
            minHeap.pop();

            result.push_back({nums1[i], nums2[j]});  // Store the corresponding pair

            // If possible, push the next pair from the same row (nums1[i], nums2[j+1])
            if (j + 1 < nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }
};
