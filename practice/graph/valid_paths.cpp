// Count Valid Paths in a Tree

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Sieve algo
    vector<bool> genPrimes(int n)
    {
        vector<bool> prime(n + 1);

        if (n > 1)
            fill(prime.begin() + 2, prime.end(), true);

        for (int i = 2; i <= n; ++i)
            if (prime[i])
                for (int j = i + i; j <= n; j += i)
                    prime[j] = false;

        return prime;
    }

    // At a particular node, we have cur[0] and cur[1] which is used to update the ans.
    // cur[0] represents no. of paths in this tree which do not contain any prime node.
    // cur[1] represents no. of paths in this tree which contain only one prime node.
    vector<int> dfs(int node, int parent, vector<bool> isPrime, long long int &ans, vector<vector<int>> adj)
    {
        // Since indexing starts from 1
        int prime = isPrime[node + 1];
        vector<int> cur(2);
        cur[prime]++;

        // Recursively traverse the tree.
        for (int y : adj[node])
        {
            if (y == parent)
            {
                continue;
            }
            vector<int> v = dfs(y, node, isPrime, ans, adj);

            // by doing both, we are also considering the paths which begin at any one child subtree and end at any other child subtree of this node
            ans += (long long)v[0] * cur[1];
            ans += (long long)v[1] * cur[0];

            if (prime)
            {
                cur[1] += v[0];
            }
            else
            {
                cur[0] += v[0];
                cur[1] += v[1];
            }
        }

        return cur;
    }

    // Function to count paths in a tree graph where some nodes are prime and others are not.
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        // Generate a vector to store whether each node is prime.
        vector<bool> isPrime = genPrimes(n);

        // Create an adjacency list representation of the tree.
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i)
        {
            int u = edges[i][0], v = edges[i][1];
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long int ans = 0;

        // Start DFS from the root node (node 0) with parent -1.
        vector<int> temp = dfs(0, -1, isPrime, ans, adj);

        return ans;
    }
};
