#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Define an edge as a pair of {weight, destination}
typedef pair<int, int> Edge;

class Graph {
    int V;
    vector<vector<Edge>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({weight, v});
        adj[v].push_back({weight, u}); // Undirected
    }

    // Finds the shortest path from start vertex to all others
    void dijkstra(int start) {
        // Min-heap priority queue: stores {distance, vertex}
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        vector<int> dist(V, numeric_limits<int>::max());

        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Skip if we found a shorter path already
            if (currentDist > dist[u]) continue;

            // Check all neighbors
            for (auto& edge : adj[u]) {
                int weight = edge.first;
                int v = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra Distances from vertex " << start << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "To " << i << " -> " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 4, 2);

    g.dijkstra(0);
    return 0;
}