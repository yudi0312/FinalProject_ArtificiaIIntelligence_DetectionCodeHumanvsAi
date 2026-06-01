#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Edge;

class Graph {
    int V;
    vector<vector<Edge>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({weight, v});
        adj[v].push_back({weight, u});
    }

    // Prim's algorithm to find MST
    void primMST() {
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        vector<bool> inMST(V, false);
        vector<int> key(V, 1e9); // Stores minimum weight to connect
        vector<int> parent(V, -1);

        int start = 0;
        pq.push({0, start});
        key[start] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (auto& edge : adj[u]) {
                int weight = edge.first;
                int v = edge.second;

                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        cout << "Prim's Minimum Spanning Tree Edges:\n";
        int totalCost = 0;
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
            totalCost += key[i];
        }
        cout << "Total Cost: " << totalCost << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);

    g.primMST();
    return 0;
}