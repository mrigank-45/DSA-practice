// Count Valid Paths in a Tree

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to generate a vector of boolean values where prime[i] is true if 'i' is prime.
    // Sieve algo
    vector<bool> genPrimes(int n)
    {
        vector<bool> prime(n + 1);

        // Initialize all numbers as potential prime numbers (true).
        if (n > 1)
            fill(prime.begin() + 2, prime.end(), true);

        // Sieve of Eratosthenes algorithm: Mark multiples of each prime number as non-prime.
        for (int i = 2; i <= n; ++i)
            if (prime[i])
                for (int j = i + i; j <= n; j += i)
                    prime[j] = false;

        return prime;
    }

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
            ans += (long long)v[0] * cur[1];
            ans += (long long)v[1] * cur[0];
            cur[prime] += v[0];

            // If the current node is not prime, update the count for prime nodes.
            if (!prime)
            {
                cur[1 + prime] += v[1];
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
