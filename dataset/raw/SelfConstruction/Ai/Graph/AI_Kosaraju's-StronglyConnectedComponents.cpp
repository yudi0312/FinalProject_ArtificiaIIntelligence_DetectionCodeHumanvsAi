#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    void fillOrder(int v, vector<bool>& visited, stack<int>& st) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) fillOrder(neighbor, visited, st);
        }
        st.push(v);
    }

    void DFS(int v, vector<bool>& visited, vector<vector<int>>& revAdj) {
        visited[v] = true;
        cout << v << " ";
        for (int neighbor : revAdj[v]) {
            if (!visited[neighbor]) DFS(neighbor, visited, revAdj);
        }
    }

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void kosarajuSCC() {
        stack<int> st;
        vector<bool> visited(V, false);

        // 1. Fill vertices in stack according to completion time
        for (int i = 0; i < V; i++) {
            if (!visited[i]) fillOrder(i, visited, st);
        }

        // 2. Reverse the graph
        vector<vector<int>> revAdj(V);
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) revAdj[neighbor].push_back(i);
        }

        // 3. Process vertices in order defined by stack
        fill(visited.begin(), visited.end(), false);
        cout << "Kosaraju's SCCs:\n";
        while (!st.empty()) {
            int v = st.top();
            st.pop();

            if (!visited[v]) {
                cout << "SCC: ";
                DFS(v, visited, revAdj);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    g.kosarajuSCC();
    return 0;
}