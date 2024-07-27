#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> values;
long long total = 0;

void dfs(int node, int parent, vector<int> &path)
{
    path.push_back(values[node]);

    if (path.size() % 2 == 1)
    {

        vector<int> sorted_path = path;
        sort(sorted_path.begin(), sorted_path.end());
        int median = sorted_path[sorted_path.size() / 2];
        total += median;
    }

    for (int neighbor : tree[node])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, node, path);
        }
    }

    path.pop_back();
}

long long solve(int n, vector<int> c, vector<vector<int>> edges)
{
    values = c;
    tree.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        u = edges[i][0];
        v = edges[i][1];
        --u;
        --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> path;
    dfs(0, -1, path);

    return total;
}

int main()
{
    int n = 10;
    vector<int> c = {3,20,4,20,17,11,6,16,14,12};
    vector<vector<int>> edges = {{4,3}, {6,5}, {5,10}, {4,9}, {7,5}, {4,6}, {1,7}, {2,4}, {8,4}};

    cout<< solve(n, c, edges) << endl;

    return 0;
}
