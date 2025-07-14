#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int u, v, w, id;
    Edge(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {}
};

int V, W, T;
vector<vector<pair<int,int>>> graph;
vector<int> disc, low, parentUF, sz;
vector<bool> visited, isBridge;
vector<Edge> edges;

int findUF(int x) {
    return parentUF[x] == x ? x : parentUF[x] = findUF(parentUF[x]);
}

void unionUF(int a, int b) {
    a = findUF(a);
    b = findUF(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parentUF[b] = a;
        sz[a] += sz[b];
    }
}

void dfs(int u, int p, int eid) {
    visited[u] = true;
    disc[u] = low[u] = T++;
    for (auto &pr : graph[u]) {
        int v = pr.first, id = pr.second;
        if (v == p && id == eid) continue;
        if (!visited[v]) {
            dfs(v, u, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) isBridge[id] = true;
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> W;
    graph.assign(V, {});
    disc.assign(V, -1);
    low.assign(V, -1);
    visited.assign(V, false);
    isBridge.assign(W, false);
    for (int i = 0; i < W; i++) {
        int s, t, l;
        cin >> s >> t >> l;
        edges.emplace_back(s, t, l, i);
        graph[s].emplace_back(t, i);
        graph[t].emplace_back(s, i);
    }

    T = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i, -1, -1);
    }

    parentUF.resize(V);
    sz.assign(V, 1);
    for (int i = 0; i < V; i++) parentUF[i] = i;

    for (auto &e : edges) {
        if (!isBridge[e.id]) unionUF(e.u, e.v);
    }

    int bestRoot = -1, bestSize = 0;
    for (int i = 0; i < V; i++) {
        int r = findUF(i);
        if (sz[r] > bestSize) {
            bestSize = sz[r];
            bestRoot = r;
        }
    }

    vector<bool> inComp(V, false);
    for (int i = 0; i < V; i++) {
        if (findUF(i) == bestRoot) inComp[i] = true;
    }
    if (bestSize <= 1) {
        cout << 0 << "\n";
        return 0;
    }

    vector<tuple<int,int,int>> mstEdges;
    for (auto &e : edges) {
        if (!isBridge[e.id] && inComp[e.u] && inComp[e.v]) {
            mstEdges.emplace_back(e.w, e.u, e.v);
        }
    }

    sort(mstEdges.begin(), mstEdges.end());

    for (int i = 0; i < V; i++) parentUF[i] = i, sz[i] = 1;
    ll ans = 0;
    int rem = bestSize;
    for (auto &t : mstEdges) {
        int w, u, v;
        tie(w, u, v) = t;
        if (findUF(u) != findUF(v)) {
            ans += w;
            unionUF(u, v);
            rem--;
            if (rem == 1) break;
        }
    }

    cout << ans << "\n";
    return 0;
}
