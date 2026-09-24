#include <iostream>
#include <vector>
#include <queue>
#include <limits> // For numeric_limits

using namespace std;

// BFS function to traverse the graph
void bfs(const vector<vector<int>>& adjList, int startVertex) {
    int n = adjList.size();
    vector<bool> visited(n, false); // Track visited vertices
    queue<int> q; // Queue for BFS

    // Start BFS from the given vertex
    visited[startVertex] = true;
    q.push(startVertex);

    cout << "BFS Traversal starting from vertex " << startVertex << ": ";

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        // Visit all adjacent vertices
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices, edges;

    // Input number of vertices
    cout << "Enter number of vertices: ";
    while (!(cin >> vertices) || vertices <= 0) {
        cout << "Invalid input. Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Input number of edges
    cout << "Enter number of edges: ";
    while (!(cin >> edges) || edges < 0) {
        cout << "Invalid input. Enter a non-negative integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Create adjacency list
    vector<vector<int>> adjList(vertices);

    cout << "Enter edges (format: u v) where u and v are vertex indices (0 to " << vertices - 1 << "):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        while (!(cin >> u >> v) || u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid edge. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // Add edge (undirected graph)
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int startVertex;
    cout << "Enter starting vertex for BFS: ";
    while (!(cin >> startVertex) || startVertex < 0 || startVertex >= vertices) {
        cout << "Invalid vertex. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Perform BFS
    bfs(adjList, startVertex);

    return 0;
}
