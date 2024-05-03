#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long computeMaxCandies(int days, int giftsCount, vector<vector<int>>& giftList) {
    vector<set<int>> giftsByDay(days + 1);
    for (int i = 0; i < giftsCount; i++) {
        int day = giftList[i][0];
        int value = giftList[i][1];
        giftsByDay[day].insert(value);
    }

    long long totalCandies = 0;
    int remainingDays = days;
    multiset<int> currentGifts;

    for (int i = 1; i <= days; i++) {
        for (auto gift : giftsByDay[i]) {
            currentGifts.insert(gift);
        }
        
        if (currentGifts.empty()) {
            remainingDays--;
            continue;
        }

        auto maxCandy = prev(currentGifts.end());
        totalCandies = (totalCandies % MOD + ((*maxCandy % MOD) * (remainingDays % MOD)) % MOD) % MOD;
        remainingDays--;
        currentGifts.erase(maxCandy);
    }
    
    return totalCandies % MOD;
}

int main() {
    int days, giftsCount;
    cin >> days >> giftsCount;

    vector<vector<int>> giftList(giftsCount, vector<int>(2));

    for (int i = 0; i < giftsCount; i++) {
        cin >> giftList[i][0] >> giftList[i][1];
    }

    cout << computeMaxCandies(days, giftsCount, giftList) << endl;

    return 0;
}
