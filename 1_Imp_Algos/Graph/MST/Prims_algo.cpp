// Used to find minimum spanning tree (applicable to only connected undirected graphs with weights)

// ALGO : Use 3 array(weight array, inMST array, parent array) and a min heap {weight,node}
// Push 0 in heap, till heap is not empty, extract top, mark MST array true, see if weight can be updated of neighbors, if yes, update weight, parent and insert in heap as well.
// make result array using parent and weight array.

//  Time Complexity = O(E*log(V))
//  Space Complexity = O(V + E)

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> primsMST(vector<pair<int, int>> *adjList, int n)
{
    // pair {min weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

    int src = 0;

    // Create vector for key and intilize as infinite. (structure 1)
    int weight[n];

    // To store parent arr. (structure 2)
    int parent[n];

    // To keep track of vertices which all ready has been included in mst. (structure 3)
    bool inMST[n];

    // initialize all structures
    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }

    inMST[src] = true;
    pq.push({0, src});
    weight[src] = 0;

    // everytime weight array is updated, element is inserted to the heap.
    while (!pq.empty())
    {
        // extract node from heap (step 1)
        int u = pq.top().second;
        pq.pop();

        // Include u to in our MST. (step 2)
        inMST[u] = true;

        // Explore all adjacent of u. (step 3)
        for (auto x : adjList[u])
        {
            int v = x.first;
            int wt = x.second;

            // If v is not in mst and weight of (u,v) is smaller then the current weight of v.
            if (!inMST[v] && weight[v] > wt)
            {
                // Update weight of v.
                weight[v] = wt;

                // Insert it into the priority queue.
                pq.push({weight[v], v});

                parent[v] = u;
            }
        }
    }

    // store ans using parent and weight array.
    vector<pair<pair<int, int>, int>> result; // {{node1,node2},weight}
    for (int i = 1; i < n; i++)
    {
        result.push_back({{parent[i], i}, weight[i]});
    }

    return result;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) // {{node1,node2},weight}
{
    // {node,node,weight}
    vector<pair<int, int>> adjList[n];

    for (int i = 0; i < m; i++) 
    {
        adjList[g[i].first.first].push_back({g[i].first.second, g[i].second});
        adjList[g[i].first.second].push_back({g[i].first.first, g[i].second});
    }

    return primsMST(adjList, n);
}
