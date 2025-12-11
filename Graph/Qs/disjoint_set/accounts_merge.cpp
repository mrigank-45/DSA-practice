// Accounts Merge

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailToNode;

        // Map each email to a person and union emails of same person
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailToNode.find(mail) == mailToNode.end()) {//mail DNE in map
                    mailToNode[mail] = i;
                } else {
                    ds.UnionBySize(i, mailToNode[mail]);
                }
            }
        }

        // Group emails by parent
        vector<vector<string>> merged(n);
        for (auto& it : mailToNode) {
            string mail = it.first;
            int parent = ds.findParent(it.second);//parent -> node
            merged[parent].push_back(mail);
        }

        //  final result
        vector<vector<string>> result;
        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);  // name eg. John
            for (auto& mail : merged[i]) {
                temp.push_back(mail);
            }
            result.push_back(temp);
        }

        return result;
    }
};
