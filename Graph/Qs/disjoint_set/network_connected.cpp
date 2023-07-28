// Number of Operations to Make Network Connected:  we need a minimum of nc-1 edges (nc = no. of components of the graph) to make the graph connected. And according to the
// question, to add these nc-1 edges, the graph must contain a minimum of nc-1 extra edges. we will check the count of extra edges and the number of components. If the count
// of extra-edges is greater or the same, we will return the answer that is (number of components – 1), and otherwise, we will return -1.

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);
        int cntExtraEdges = 0;

        // count extra edges
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            // if both has same parent, then this is an extra edge
            if (ds.findUPar(u) == ds.findUPar(v))
            {
                cntExtraEdges++;
            }
            else
            {
                ds.unionByRank(u, v);
            }
        }
        int cntComponents = 0;

        // count no. of disconnected components
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i) // if a node is it's own parent, then it's a separate component
            {
                cntComponents++;
            }
        }
        int ans = cntComponents - 1;
        if (cntExtraEdges >= ans)
            return ans;
        return -1;
    }
};

int main()
{

    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    Solution obj;
    int ans = obj.Solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;
}
