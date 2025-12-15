#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    int size = 0;
    int capacity;
    unordered_map<int, pair<int, int>> keyToValFreq; // key -> {value, freq}
    map<int,vector<int>> freqToKeys; // freq -> keys

    LFUCache(int capacity) {
        capacity = capacity;
    }
    
    int get(int key) {
        if(keyToValFreq.find(key) == keyToValFreq.end()) return -1;
        
        int value = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;
        keyToValFreq[key].second++;

        vector<int> keys = freqToKeys[freq];
        keys.erase(remove(keys.begin(), keys.end(), key), keys.end());
        if(keys.empty()){
            freqToKeys.erase(freq);
        }
        freqToKeys[freq + 1].push_back(key);

        return value;
    }
    
    void put(int key, int value) {
        if(size == capacity && keyToValFreq.find(key) == keyToValFreq.end()){
            int leastFreq = freqToKeys.begin()->first;
            int keyToRemove = freqToKeys[leastFreq].front();
            freqToKeys[leastFreq].erase(freqToKeys[leastFreq].begin());
            if(freqToKeys[leastFreq].empty()){
                freqToKeys.erase(leastFreq);
            }
            keyToValFreq.erase(keyToRemove);
            size--;
        }

        if(keyToValFreq.find(key) != keyToValFreq.end()){
            keyToValFreq[key].first = value;
            get(key); // Update frequency
        } else {
            keyToValFreq[key] = {value, 1};
            freqToKeys[1].push_back(key);
            size++;
        }
    }
};
