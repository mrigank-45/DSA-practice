#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Function to find the minimum extra chocolates needed
int solution(int A, int B) {
    // If B is already a multiple of A, no extra chocolates are needed
    if (B % A == 0) {
        return 0;
    }

    // Initialize minimum extra chocolates to a large value
    int minChocolates = INT_MAX;

    // Iterate over possible values of k
    for (int k = 1; k <= B / A + 1; ++k) {
        // Calculate the new B (B + Y)
        int newB = k * A;

        // Ensure newB is greater than or equal to the current B
        if (newB >= B) {
            // Calculate Y as the difference between newB and B
            int Y = newB - B;

            // Calculate X needed to make A + X equal to newB / k
            int X = newB / k - A;

            // Update the minimum extra chocolates needed
            if (X >= 0 && Y >= 0) {
                minChocolates = min(minChocolates, X + Y);
            }
        }
    }

    return minChocolates;
}

int main() {
    // Sample test case
    int A = 8, B = 16;

    // Call the solution function and output the result
    cout << "Sample Input: A = " << A << ", B = " << B << endl;
    cout << "Sample Output: " << solution(A, B) << endl;

    // Additional test cases
    cout << "\nAdditional Test Cases:\n";

    // Example 1
    A = 3, B = 9;
    cout << "Input: A = " << A << ", B = " << B << endl;
    cout << "Output: " << solution(A, B) << endl;

    // Example 2
    A = 7, B = 20;
    cout << "Input: A = " << A << ", B = " << B << endl;
    cout << "Output: " << solution(A, B) << endl;

    return 0;
}
