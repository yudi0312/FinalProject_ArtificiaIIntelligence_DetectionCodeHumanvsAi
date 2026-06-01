#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findConnectedComponents() {
        vector<bool> visited(V, false);
        int componentCount = 0;

        cout << "Connected Components:\n";
        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                cout << "Component " << ++componentCount << ": ";
                dfs(v, visited);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1); // Component 1
    g.addEdge(2, 3); // Component 2
    g.addEdge(3, 4); 

    g.findConnectedComponents();
    return 0;
}