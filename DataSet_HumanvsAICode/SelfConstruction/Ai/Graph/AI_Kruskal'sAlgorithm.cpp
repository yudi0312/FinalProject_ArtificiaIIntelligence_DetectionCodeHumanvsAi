#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Disjoint Set Union (Union-Find) class
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            if (rank[rootI] < rank[rootJ]) parent[rootI] = rootJ;
            else if (rank[rootI] > rank[rootJ]) parent[rootJ] = rootI;
            else {
                parent[rootJ] = rootI;
                rank[rootI]++;
            }
        }
    }
};

// Custom comparator to sort edges by weight
bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compareEdges);
    DSU dsu(V);
    int totalCost = 0;

    cout << "Kruskal's Minimum Spanning Tree Edges:\n";
    for (auto& edge : edges) {
        // If including this edge doesn't cause a cycle
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            dsu.unite(edge.src, edge.dest);
            totalCost += edge.weight;
            cout << edge.src << " - " << edge.dest << " (Weight: " << edge.weight << ")\n";
        }
    }
    cout << "Total Cost: " << totalCost << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    kruskalMST(edges, V);
    return 0;
}