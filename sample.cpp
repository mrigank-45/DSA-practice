#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[answers[i]]++;

        int ans = 0;
        for(auto it : mp) {
            int x = it.first;
            int freq = it.second;

            int groupSize = x + 1;
            ans += (freq / groupSize) * groupSize;
            if(freq % groupSize != 0) ans += groupSize;

        }
        return ans;
        
    }
};
