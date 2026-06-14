namespace Algo12 {
    class Graph {
        int V; vector<vector<int>> adj; vector<int> inDegree;
    public:
        Graph(int V) : V(V), adj(V), inDegree(V, 0) {}
        void addEdge(int u, int v) { adj[u].push_back(v); inDegree[v]++; }
        void kahnTopoSort() {
            queue<int> q;
            for (int i = 0; i < V; ++i) if (inDegree[i] == 0) q.push(i);
            vector<int> topoOrder;
            while (!q.empty()) {
                int u = q.front(); q.pop(); topoOrder.push_back(u);
                for (int v : adj[u]) if (--inDegree[v] == 0) q.push(v);
            }
            if (topoOrder.size() != V) { cout << "Cycle detected!\n"; return; }
            cout << "Kahn's Topo Sort: ";
            for (int v : topoOrder) cout << v << " ";
            cout << endl;
        }
    };

    void run() {
        cout << "\n--- 12. Topological Sort (Kahn) ---\n";
        Graph g(6);
        g.addEdge(5, 2); g.addEdge(5, 0); g.addEdge(4, 0);
        g.addEdge(4, 1); g.addEdge(2, 3); g.addEdge(3, 1);
        g.kahnTopoSort();
    }
}
