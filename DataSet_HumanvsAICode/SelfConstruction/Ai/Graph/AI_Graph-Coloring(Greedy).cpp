#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void greedyColoring() {
        vector<int> result(V, -1); // Array to store color assignments
        result[0] = 0; // Assign color 0 to the first vertex

        vector<bool> available(V, false);

        for (int u = 1; u < V; u++) {
            // Mark colors of adjacent vertices as unavailable
            for (int i : adj[u]) {
                if (result[i] != -1) available[result[i]] = true;
            }

            // Find the first available color
            int cr;
            for (cr = 0; cr < V; cr++) {
                if (available[cr] == false) break;
            }

            result[u] = cr; // Assign found color

            // Reset the values back to false for the next iteration
            for (int i : adj[u]) {
                if (result[i] != -1) available[result[i]] = false;
            }
        }

        cout << "Greedy Graph Coloring:\n";
        for (int u = 0; u < V; u++) {
            cout << "Vertex " << u << " ---> Color " << result[u] << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.greedyColoring();
    return 0;
}