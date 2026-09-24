#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

// Function to perform DFS using an explicit stack
void dfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;

    // Start DFS from the given node
    st.push(start);
    visited[start] = true;

    cout << "DFS Traversal starting from vertex " << start << ": ";

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        cout << node << " ";

        // Push unvisited neighbors onto the stack
        // Reverse order to mimic recursive DFS behavior
        for (int i = adj[node].size() - 1; i >= 0; --i) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    if (!(cin >> vertices) || vertices <= 0) {
        cerr << "Invalid number of vertices.\n";
        return 1;
    }

    cout << "Enter number of edges: ";
    if (!(cin >> edges) || edges < 0) {
        cerr << "Invalid number of edges.\n";
        return 1;
    }

    vector<vector<int>> adj(vertices);

    cout << "Enter edges (u v) where u and v are vertex indices (0 to " << vertices - 1 << "):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        if (!(cin >> u >> v) || u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cerr << "Invalid edge input.\n";
            return 1;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    int startVertex;
    cout << "Enter starting vertex for DFS: ";
    if (!(cin >> startVertex) || startVertex < 0 || startVertex >= vertices) {
        cerr << "Invalid starting vertex.\n";
        return 1;
    }

    dfs(startVertex, adj);

    return 0;
}
