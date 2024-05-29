#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int solve(int N, int M, int K, vector<int> &price, vector<int> &protein, int i) {
    if (i == N || M == 0) {
        return 0;
    }

    if (memo[i][M] != -1) {
        return memo[i][M];
    }

    int half_price = price[i] / 2;

    int ans = 0;

    ans = solve(N, M, K, price, protein, i + 1);

    if (M >= price[i]) {
        ans = max(ans, solve(N, M - price[i], K, price, protein, i + 1) + protein[i]);
    }

    if (K > 0 && M >= half_price) {
        ans = max(ans, solve(N, M - half_price, K - 1, price, protein, i + 1) + protein[i]);
    }

    memo[i][M] = ans;
    return ans;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> price(N);
    vector<int> protein(N);

    for (int i = 0; i < N; ++i) {
        cin >> price[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> protein[i];
    }

    memo.assign(N, vector<int>(M + 1, -1));

    int ans = solve(N, M, K, price, protein, 0);
    cout << ans << endl;

    return 0;
}
