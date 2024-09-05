#include <bits/stdc++.h>
using namespace std;

int solution(vector<int>& A, vector<int>& B, int N) {
    vector<int> max_top(N), max_bottom(N);
    
    max_top[0] = A[0];
    for (int i = 1; i < N; i++) {
        max_top[i] = max(max_top[i - 1], A[i]);
    }
    
    max_bottom[N-1] = B[N-1];
    for (int i = N - 2; i >= 0; i--) {
        max_bottom[i] = max(max_bottom[i + 1], B[i]);
    }
    
    int result = 1e9 + 10;
    
    for (int i = 0; i < N; i++) {
        int current_max = max(max_top[i], max_bottom[i]);
        result = min(result, current_max);
    }
    
    return result;
}

int main() {
    // Example test cases
    vector<int> A = {3, 4, 6};
    vector<int> B = {6, 5, 4};
    int N = A.size();
    cout << solution(A, B, N) << endl;  // Output: 5

    vector<int> A2 = {1, 2, 1, 1, 4};
    vector<int> B2 = {1, 1, 3, 1, 1};
    N = A2.size();
    cout << solution(A2, B2, N) << endl;  // Output: 2

    vector<int> A3 = {-5, -1, -3};
    vector<int> B3 = {-5, 5, -2};
    N = A3.size();
    cout << solution(A3, B3, N) << endl;  // Output: -1

    return 0;
}
