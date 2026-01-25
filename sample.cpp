#include <bits/stdc++.h>
using namespace std;

class StockPrice {
public:
    int latest_time;
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
    priority_queue<pair<int,int>> max_heap;

    StockPrice() {
        latest_time = -1;
    }
    
    void update(int timestamp, int price) {
        mp[timestamp] = price;
        if(timestamp>latest_time) latest_time = timestamp;
        max_heap.push({price,timestamp});
        min_heap.push({price,timestamp});
    }
    
    int current() {
        return mp[latest_time];
    }
    
    int maximum() {
        while(!max_heap.empty() && max_heap.top().first != mp[max_heap.top().second]){
            max_heap.pop();
        }
        return max_heap.top().first;
        
    }
    
    int minimum() {
         while(!min_heap.empty() && min_heap.top().first != mp[min_heap.top().second]){
            min_heap.pop();
        }
        return min_heap.top().first;
        
    }
};
