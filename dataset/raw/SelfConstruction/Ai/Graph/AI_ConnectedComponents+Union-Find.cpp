#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
    vector<int> parent;
    int components;

public:
    UnionFind(int n) : parent(n), components(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ; // Merge components
            components--;          // Total components decrease
        }
    }

    int getComponentCount() {
        return components;
    }
};

int main() {
    int V = 5;
    UnionFind uf(V);

    // Edges
    uf.unite(0, 1);
    uf.unite(2, 3);
    uf.unite(3, 4);

    cout << "Number of connected components (Union-Find): " << uf.getComponentCount() << endl;

    return 0;
}