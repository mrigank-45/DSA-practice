#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        int ans = 0;
        int curr = 1;
        string curr_str = "";
        unordered_set<string> st;
        vector<bool> count(26, 0);
        for (int i = 0; i < n; ++i) {
            if (i > 0 && ((s[i] - s[i - 1]) + 26) % 26 == 1) {
                curr++;
                curr_str += s[i];

            } else {
                if(curr>1 && st.find(curr_str) == st.end()) {
                    ans += (curr * (curr - 1)) / 2;
                    st.insert(curr_str);
                }
                curr = 1;
                curr_str = "";
                curr_str += s[i];
            }
            if (!count[s[i] - 'a']) {
                count[s[i] - 'a'] = 1;
                ans++;
            }
        }
        if(curr>1 && st.find(curr_str) == st.end()) ans += (curr * (curr - 1)) / 2;
        return ans;
    }
};
