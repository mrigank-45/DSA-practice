#include <bits/stdc++.h>
using namespace std;

long countSpecialSubarrays(vector<int> arr) {
    int n = arr.size();
    unordered_map<int, int> prefixCount;
    int currentParity = 0;
    long specialCount = 0;

    // Initial case: empty subarray has parity 0
    prefixCount[0] = 1;

    for (int num : arr) {
        // Calculate the parity of the current number
        int parity = num % 2;

        // Update the current parity
        currentParity ^= parity;

        // Count the number of special subarrays ending at the current position
        specialCount += prefixCount[currentParity];

        // Update the hash map with the current parity
        prefixCount[currentParity]++;
    }

    return specialCount;
}


int main() {
    // vector<int> arr = {4, 3, 12};  // Example input
    vector<int> arr = {9, 9, 9};  // Another example input
    // vector<int> arr = {2, 1, 1};  // Another example input

    int result = countSpecialSubarrays(arr);
    cout << "Number of special subarrays: " << result << endl;
    return 0;
}
