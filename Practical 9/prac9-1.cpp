
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void DFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        cout << node << " ";

        // Push neighbors in reverse order to visit smaller nodes first
        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];
            if (!visited[neighbor])
                s.push(neighbor);
        }
    }
}

void BFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of buildings and roads: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);

    cout << "Enter roads (building1 building2):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting building: ";
    cin >> start;

    vector<bool> visitedDFS(n, false);
    vector<bool> visitedBFS(n, false);

    cout << "\nDFS Traversal: ";
    DFS(start, adj, visitedDFS);

    cout << "\nBFS Traversal: ";
    BFS(start, adj, visitedBFS);

    cout << endl;
    return 0;
}
