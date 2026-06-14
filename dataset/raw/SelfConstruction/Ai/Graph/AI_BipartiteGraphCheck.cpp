#include <iostream>
#include <vector>
#include <queue>

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

    bool isBipartite() {
        vector<int> color(V, -1); // -1 means uncolored

        for (int i = 0; i < V; ++i) {
            if (color[i] == -1) { // Process unvisited components
                queue<int> q;
                q.push(i);
                color[i] = 0; // Assign first color

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u]; // Alternate color
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false; // Conflict found
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0); // Even cycle -> Bipartite

    if (g.isBipartite()) cout << "Graph is Bipartite." << endl;
    else cout << "Graph is not Bipartite." << endl;

    return 0;
}