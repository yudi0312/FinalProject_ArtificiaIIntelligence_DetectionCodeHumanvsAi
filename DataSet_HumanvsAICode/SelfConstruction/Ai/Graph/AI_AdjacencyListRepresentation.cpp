#include <iostream>
#include <vector>

using namespace std;

// Class representing a graph using an adjacency list
class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList; // Adjacency list

public:
    Graph(int V) {
        numVertices = V;
        adjList.resize(V);
    }

    // Add an undirected edge
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    // Print the graph representation
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << ":";
            for (int neighbor : adjList[i]) {
                cout << " -> " << neighbor;
            }
            cout << endl;
        }
    }
};

int main() {
    // Example usage
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    
    cout << "Adjacency List:\n";
    g.printGraph();
    
    return 0;
}