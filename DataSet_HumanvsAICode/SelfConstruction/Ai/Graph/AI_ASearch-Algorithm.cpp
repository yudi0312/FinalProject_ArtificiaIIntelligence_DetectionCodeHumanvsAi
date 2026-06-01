#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Representing nodes with (x, y) coordinates for heuristic estimation
struct Node {
    int id, x, y;
};

// Edge for standard traversal
struct Edge {
    int dest, weight;
};

struct AStarState {
    int f_score, id;
    bool operator>(const AStarState& other) const {
        return f_score > other.f_score; // Min-heap based on f-score
    }
};

class Graph {
    int V;
    vector<Node> nodes;
    vector<vector<Edge>> adj;

    // Euclidean distance heuristic
    int heuristic(int u, int target) {
        return sqrt(pow(nodes[u].x - nodes[target].x, 2) + pow(nodes[u].y - nodes[target].y, 2));
    }

public:
    Graph(int V) : V(V), adj(V) {}

    void setNode(int id, int x, int y) {
        if (id >= nodes.size()) nodes.resize(id + 1);
        nodes[id] = {id, x, y};
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    void aStarSearch(int start, int target) {
        priority_queue<AStarState, vector<AStarState>, greater<AStarState>> pq;
        vector<int> g_score(V, 1e9);

        g_score[start] = 0;
        pq.push({heuristic(start, target), start});

        while (!pq.empty()) {
            int current = pq.top().id;
            pq.pop();

            if (current == target) {
                cout << "A* Reached target " << target << " with distance " << g_score[target] << endl;
                return;
            }

            for (auto& edge : adj[current]) {
                int neighbor = edge.dest;
                int tentative_g = g_score[current] + edge.weight;

                if (tentative_g < g_score[neighbor]) {
                    g_score[neighbor] = tentative_g;
                    int f_score = tentative_g + heuristic(neighbor, target);
                    pq.push({f_score, neighbor});
                }
            }
        }
        cout << "Target not reachable." << endl;
    }
};

int main() {
    Graph g(4);
    // Setup heuristic coordinates
    g.setNode(0, 0, 0);
    g.setNode(1, 0, 5);
    g.setNode(2, 5, 0);
    g.setNode(3, 5, 5);

    g.addEdge(0, 1, 6);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 6);

    g.aStarSearch(0, 3);
    return 0;
}
