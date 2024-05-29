#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

struct FoodItem
{
    int price;
    int protein;
};

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<FoodItem> items(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> items[i].price;
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> items[i].protein;
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(K + 1, 0)));

    for (int i = 1; i <= N; ++i)
    {
        int price = items[i - 1].price;
        int half_price = price / 2;
        int protein = items[i - 1].protein;

        for (int j = 0; j <= M; ++j)
        {
            for (int k = 0; k <= K; ++k)
            {
                dp[i][j][k] = dp[i - 1][j][k];

                if (j >= price)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - price][k] + protein);
                }

                if (k > 0 && j >= half_price)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - half_price][k - 1] + protein);
                }
            }
        }
    }

    int max_protein = 0;
    for (int k = 0; k <= K; ++k)
    {
        max_protein = max(max_protein, dp[N][M][k]);
    }

    cout << max_protein << endl;

    return 0;
}
