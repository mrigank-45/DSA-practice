#include <bits/stdc++.h>
using namespace std;

int minSwaps(string s, char c) {
    int n = s.size();
    int total = 0;
    
    // Count the total number of character c in the string
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            total++;
        }
    }
    
    // If the character c is not present or already the entire string, no swaps needed
    if (total == 0 || total == n) {
        return 0;
    }

    // Sliding window to count the minimum swaps required
    int max_count_in_window = 0;
    int current_count = 0;

    // Initialize the first window
    for (int i = 0; i < total; i++) {
        if (s[i] == c) {
            current_count++;
        }
    }
    max_count_in_window = current_count;

    // Slide the window across the string
    for (int i = total; i < n; i++) {
        if (s[i - total] == c) {
            current_count--;
        }
        if (s[i] == c) {
            current_count++;
        }
        max_count_in_window = max(max_count_in_window, current_count);
    }

    // The minimum swaps required is the difference between total count and max_count_in_window
    return total - max_count_in_window;
}

int main() {
    string s = "agbggcggbcvnxjkmsdkdgggg";
    char c = 'g';
    cout << minSwaps(s, c) << endl;
    return 0;
}
