#include <bits/stdc++.h>
using namespace std;

vector<int> findDistinctGoodnessValues(const vector<int>& arr) {
    set<int> goodnessSet;
    goodnessSet.insert(0); 

    map<int, set<int>> dp;

    for (int num : arr) {
        map<int, set<int>> newDp = dp;
        for (auto it : dp) {
            int key = it.first;
            set<int> values = it.second;
            if (key < num) {
                for (int val : values) {
                    newDp[num].insert(val | num);
                }
            }
        }
        newDp[num].insert(num);
        for (int val : newDp[num]) {
            goodnessSet.insert(val);
        }
        dp = newDp;
    }

    return vector<int>(goodnessSet.begin(), goodnessSet.end());
}

int main() {
    vector<int> arr = {3,5,5,1};
    vector<int> result = findDistinctGoodnessValues(arr);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
