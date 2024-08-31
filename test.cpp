#include <bits/stdc++.h>
using namespace std;

// Precomputed prime numbers up to 200
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
                      53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 
                      109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 
                      173, 179, 181, 191, 193, 197, 199};

// Precompute the bit representation for each number up to 200
vector<int> computeBitRepresentation(int maxNum) {
    vector<int> bitRepresentation(maxNum + 1, 0);
    for (int i = 2; i <= maxNum; ++i) {
        int num = i;
        int bits = 0;
        for (int j = 0; j < primes.size(); ++j) {
            int prime = primes[j];
            int exponent = 0;
            while (num % prime == 0) {
                num /= prime;
                exponent++;
            }
            if (exponent % 2 != 0) {
                bits ^= (1 << j);
            }
        }
        bitRepresentation[i] = bits;
    }
    return bitRepresentation;
}

long countSpecialSubarrays(vector<int> arr) {
   int n = arr.size();
    vector<int> bitRepresentation = computeBitRepresentation(200);
    unordered_map<int, int> prefixCount;
    int currentParity = 0;
    long specialCount = 0;

    // Initial case: empty subarray has parity 0
    prefixCount[0] = 1;

    for (int num : arr) {
        currentParity ^= bitRepresentation[num];
        
        // Count the number of special subarrays ending at the current position
        if (prefixCount.find(currentParity) != prefixCount.end()) {
            specialCount += prefixCount[currentParity];
        }

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
