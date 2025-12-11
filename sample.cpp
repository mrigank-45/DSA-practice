#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    unordered_set<string> st;
    WordDictionary() {
    }
    
    void addWord(string word) {
        st.insert(word);
    }
    
    bool search(string word) {
        if (st.count(word)) return true;
        int n = word.size();
        int p1 = -1, p2 = -1;
        for(int i = 0; i < n; i++) {
            if (word[i] == '.') {
                if (p1 == -1) p1 = i;
                else p2 = i;
            }
        }
        if (p1 == -1) return false;
        if(p2 == -1) {
            for(int i = 0; i < 26; i++) {
                string modified = word;
                modified[p1] = 'a' + i;
                if (st.count(modified)) return true;
            }
        } else {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    string modified = word;
                    modified[p1] = 'a' + i;
                    modified[p2] = 'a' + j;
                    if (st.count(modified)) return true;
                }
            }
        }
        return false;
    }
};
