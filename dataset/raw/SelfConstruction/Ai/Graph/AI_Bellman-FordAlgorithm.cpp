#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void bellmanFord(int start) {
        vector<int> dist(V, numeric_limits<int>::max());
        dist[start] = 0;

        // Relax all edges V - 1 times
        for (int i = 1; i <= V - 1; i++) {
            for (auto& edge : edges) {
                if (dist[edge.src] != numeric_limits<int>::max() && 
                    dist[edge.src] + edge.weight < dist[edge.dest]) {
                    dist[edge.dest] = dist[edge.src] + edge.weight;
                }
            }
        }

        // Check for negative-weight cycles
        for (auto& edge : edges) {
            if (dist[edge.src] != numeric_limits<int>::max() && 
                dist[edge.src] + edge.weight < dist[edge.dest]) {
                cout << "Graph contains negative weight cycle!" << endl;
                return;
            }
        }

        cout << "Bellman-Ford Distances from " << start << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "To " << i << " -> " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.bellmanFord(0);
    return 0;
}