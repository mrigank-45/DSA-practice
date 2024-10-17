#include <bits/stdc++.h>
#include <chrono> 
using namespace std;

void printPath(unordered_map<int, int> &parent, int start, int meet)
{
    stack<int> path;
    int node = meet;
    while (node != start)
    {
        path.push(node);
        node = parent[node];
    }
    path.push(start);
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
}

void printPathFromMeetToEnd(unordered_map<int, int> &parentRev, int meet, int dest)
{
    int node = meet;
    while (node != dest)
    {
        node = parentRev[node];
        cout << node << " ";
    }
}

vector<vector<int>> randomGraph(int n, int edges)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }
    srand(time(0));
    for (int i = 0; i < edges; i++)
    {
        int u = rand() % n;
        int v = rand() % n;
        if (adj[u].size() == 3 || adj[v].size() == 3 || u == v)
            continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

int bidirectionalBFS(int start, int dest, vector<vector<int>> &adj, int n)
{
    queue<int> qStart, qEnd;
    unordered_map<int, int> parent, parentRev;
    vector<bool> visitedStart(n, false), visitedEnd(n, false);
    int iterations = 0;

    qStart.push(start);
    qEnd.push(dest);
    visitedStart[start] = true;
    visitedEnd[dest] = true;
    parent[start] = -1;
    parentRev[dest] = -1;

    while (!qStart.empty() && !qEnd.empty())
    {
        iterations++;
        int size = qStart.size();
        while (size--)
        {
            int curr = qStart.front();
            qStart.pop();
            for (int neighbor : adj[curr])
            {
                if (!visitedStart[neighbor])
                {
                    visitedStart[neighbor] = true;
                    qStart.push(neighbor);
                    parent[neighbor] = curr;
                    if (visitedEnd[neighbor])
                    {
                        cout << "Distance (Bidirectional): " << 2 * iterations;
                        cout << endl;
                        cout << "Path (Bidirectional): ";
                        printPath(parent, start, neighbor);
                        printPathFromMeetToEnd(parentRev, neighbor, dest);
                        cout << endl;
                        return iterations;
                    }
                }
            }
        }

        size = qEnd.size();
        while (size--)
        {
            int curr = qEnd.front();
            qEnd.pop();
            for (int neighbor : adj[curr])
            {
                if (!visitedEnd[neighbor])
                {
                    visitedEnd[neighbor] = true;
                    qEnd.push(neighbor);
                    parentRev[neighbor] = curr;
                    if (visitedStart[neighbor])
                    {
                        cout << "Distance (Bidirectional): " << 2 * iterations;
                        cout << endl;
                        cout << "Path (Bidirectional): ";
                        printPath(parent, start, neighbor);
                        printPathFromMeetToEnd(parentRev, neighbor, dest);
                        cout << endl;
                        return iterations;
                    }
                }
            }
        }
    }
    return iterations;
}

int BFS(int start, int dest, vector<vector<int>> &adj, int n)
{
    queue<int> q;
    unordered_map<int, int> parent;
    vector<bool> visited(n, false);
    int iterations = 0;

    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty())
    {
        iterations++;
        int size = q.size();
        while (size--)
        {
            int curr = q.front();
            q.pop();
            for (int neighbor : adj[curr])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    parent[neighbor] = curr;
                    if (neighbor == dest)
                    {
                        cout << "Distance (Single BFS): " << iterations;
                        cout << endl;
                        cout << "Path (Single BFS): ";
                        printPath(parent, start, dest);
                        cout << endl;
                        return iterations;
                    }
                }
            }
        }
    }
    return iterations;
}

int main()
{
    int n = 50, edges = 110, start = 5, dest = 17;
    vector<vector<int>> adj = randomGraph(n, edges);

    auto startTime = chrono::high_resolution_clock::now();
    int bidirectionalIterations = bidirectionalBFS(start, dest, adj, n);
    auto endTime = chrono::high_resolution_clock::now();
    auto durationBidirectional = chrono::duration_cast<chrono::microseconds>(endTime - startTime);
    cout << "Bidirectional BFS Iterations: " << bidirectionalIterations << endl;
    cout << "Bidirectional BFS Time: " << durationBidirectional.count() << " microseconds" << endl;

    cout<<endl;

    startTime = chrono::high_resolution_clock::now();
    int bfsIterations = BFS(start, dest, adj, n);
    endTime = chrono::high_resolution_clock::now();
    auto durationBFS = chrono::duration_cast<chrono::microseconds>(endTime - startTime);
    cout << "Single BFS Iterations: " << bfsIterations << endl;
    cout << "Single BFS Time: " << durationBFS.count() << " microseconds" << endl;

    cout<<endl;

    cout << "Iterations saved: " << bfsIterations - bidirectionalIterations << endl;

    return 0;
}
