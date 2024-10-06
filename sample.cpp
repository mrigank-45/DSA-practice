#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    unordered_map<int, pair<int, int>> mp;
    set<pair<int, int>> st;
    int max_size;
    int use_id = 1;
    LRUCache(int capacity)
    {
        max_size = capacity;
    }

    int get(int key)  // O(logn)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        st.erase({mp[key].second, key});
        use_id++;
        mp[key].second = use_id;
        st.insert({mp[key].second, key});
        return mp[key].first;
    }

    void put(int key, int value) // O(logn)
    {
        if (mp.find(key) != mp.end())
        {
            st.erase({mp[key].second, key});
            use_id++;
            mp[key] = {value, use_id};
            st.insert({mp[key].second, key});
        }
        else if (mp.size() == max_size)
        {
            mp.erase(st.begin()->second);
            st.erase(st.begin());
            use_id++;
            mp[key] = {value, use_id};
            st.insert({mp[key].second, key});
        }
        else
        {
            use_id++;
            mp[key] = {value, use_id};
            st.insert({mp[key].second, key});
        }
    }
};
