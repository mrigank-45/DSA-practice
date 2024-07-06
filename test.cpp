#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX_SIZE = 1e5 + 10;
ll MODULO = 1000000007;
vector<ll> adjacencyList[MAX_SIZE];
vector<ll> primeNumbers;
vector<vector<ll>> dynamicProgrammingTable;
ll nodeValues[MAX_SIZE];

void generatePrimes(ll limit) {
    vector<bool> isPrime(limit + 1, true);
    for (ll p = 2; p * p <= limit; p++) {
        if (!isPrime[p]) continue;
        for (ll i = p * p; i <= limit; i += p) {
            isPrime[i] = false;
        }
    }
    for (ll i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primeNumbers.push_back(i);
        }
    }
}

bool checkPrime(ll number) {
    auto it = find(primeNumbers.begin(), primeNumbers.end(), number);
    return it != primeNumbers.end();
}

void depthFirstSearch(ll currentNode, ll parentNode) {
    for (ll i = 0; i < 25; i++) {
        dynamicProgrammingTable[currentNode][i] = 1;
    }
    for (auto neighbor : adjacencyList[currentNode]) {
        if (neighbor != parentNode) {
            depthFirstSearch(neighbor, currentNode);
            for (ll i = 0; i < 25; i++) {
                ll count = 0;
                for (ll j = 0; j < 25; j++) {
                    if (!checkPrime(primeNumbers[i] + primeNumbers[j])) {
                        count = (count + dynamicProgrammingTable[neighbor][j]) % MODULO;
                    }
                }
                dynamicProgrammingTable[currentNode][i] = (dynamicProgrammingTable[currentNode][i] * count) % MODULO;
            }
        }
    }
}

ll computeGoodPaths(ll numNodes, vector<vector<ll>> &edges) {
    generatePrimes(200);
    dynamicProgrammingTable.resize(numNodes + 10, vector<ll>(25, 0));
    for (ll i = 0; i < numNodes - 1; i++) {
        adjacencyList[edges[i][0]].push_back(edges[i][1]);
        adjacencyList[edges[i][1]].push_back(edges[i][0]);
    }
    depthFirstSearch(0, -1);
    ll totalPaths = 0;
    for (ll i = 0; i < 25; i++) {
        totalPaths = (totalPaths + dynamicProgrammingTable[0][i]) % MODULO;
    }
    return totalPaths;
}

int main() {
    ll numNodes;
    cin >> numNodes;
    vector<vector<ll>> edges(numNodes - 1, vector<ll>(2));
    for (ll i = 0; i < numNodes - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << computeGoodPaths(numNodes, edges) << endl;
    return 0;
}