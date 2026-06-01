#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;

    // BFS to find an augmenting path
    bool bfs(int source, int sink, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = source;
        queue<pair<int, int>> q;
        q.push({source, numeric_limits<int>::max()});

        while (!q.empty()) {
            int u = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int v : adj[u]) {
                if (parent[v] == -1 && capacity[u][v] > 0) {
                    parent[v] = u;
                    int new_flow = min(flow, capacity[u][v]);
                    if (v == sink) return new_flow; // Reached sink
                    q.push({v, new_flow});
                }
            }
        }
        return 0; // No augmenting path found
    }

public:
    Graph(int V) : V(V), capacity(V, vector<int>(V, 0)), adj(V) {}

    void addEdge(int u, int v, int cap) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Reverse edge for residual graph
        capacity[u][v] += cap; // Directed capacity
    }

    void edmondsKarp(int source, int sink) {
        int maxFlow = 0;
        vector<int> parent(V);
        int new_flow;

        while ((new_flow = bfs(source, sink, parent))) {
            maxFlow += new_flow;
            int curr = sink;
            // Update residual capacities
            while (curr != source) {
                int prev = parent[curr];
                capacity[prev][curr] -= new_flow;
                capacity[curr][prev] += new_flow; // Add back-flow
                curr = prev;
            }
        }

        cout << "Edmonds-Karp Max Flow: " << maxFlow << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 5, 20);
    g.addEdge(4, 3, 7);
    g.addEdge(4, 5, 4);

    g.edmondsKarp(0, 5);
    return 0;
}