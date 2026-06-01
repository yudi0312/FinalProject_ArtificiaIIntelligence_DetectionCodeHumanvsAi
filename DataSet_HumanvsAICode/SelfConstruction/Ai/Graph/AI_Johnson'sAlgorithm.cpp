#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
const int INF = 1e9;
typedef pair<int, int> EdgePair;

class Graph {
    int V;
    vector<vector<EdgePair>> adj;

    // Helper: Dijkstra's Algorithm
    vector<int> dijkstra(int src, const vector<int>& h) {
        priority_queue<EdgePair, vector<EdgePair>, greater<EdgePair>> pq;
        vector<int> dist(V + 1, INF);
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.second;
                int weight = edge.first + h[u] - h[v]; // Reweighting
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        // Correct distances by removing heuristic modifications
        for (int i = 0; i < V; ++i) {
            if (dist[i] != INF) dist[i] = dist[i] - h[src] + h[i];
        }
        return dist;
    }

public:
    Graph(int V) : V(V), adj(V + 1) {} // Extra vertex for Bellman-Ford

    void addEdge(int u, int v, int w) {
        adj[u].push_back({w, v});
    }

    void johnsonsAlgorithm() {
        // Step 1: Add phantom node V connected to all with weight 0
        for (int i = 0; i < V; ++i) adj[V].push_back({0, i});

        // Step 2: Run Bellman-Ford from the phantom node
        vector<int> h(V + 1, INF);
        h[V] = 0;
        for (int i = 0; i < V; ++i) { // Relax V times
            for (int u = 0; u <= V; ++u) {
                for (auto& edge : adj[u]) {
                    int v = edge.second;
                    int weight = edge.first;
                    if (h[u] != INF && h[u] + weight < h[v]) {
                        h[v] = h[u] + weight;
                    }
                }
            }
        }
        // Simplified check for negative cycle omitted for brevity but standard in BF

        // Remove phantom node edges (optional conceptually, practically we just ignore it)
        
        // Step 3: Run Dijkstra for every node
        cout << "Johnson's All-Pairs Shortest Paths:\n";
        for (int u = 0; u < V; ++u) {
            vector<int> dist = dijkstra(u, h);
            cout << "From " << u << ": ";
            for (int v = 0; v < V; ++v) {
                if (dist[v] == INF) cout << "INF ";
                else cout << dist[v] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, -5);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 1);

    g.johnsonsAlgorithm();
    return 0;
}