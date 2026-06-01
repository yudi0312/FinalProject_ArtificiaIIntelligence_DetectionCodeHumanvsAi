#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V, time;
    vector<vector<int>> adj;

    void sccHelper(int u, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& inStack) {
        disc[u] = low[u] = ++time;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                sccHelper(v, disc, low, st, inStack);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }

        // If u is head of SCC
        if (low[u] == disc[u]) {
            cout << "SCC: ";
            while (st.top() != u) {
                cout << st.top() << " ";
                inStack[st.top()] = false;
                st.pop();
            }
            cout << st.top() << "\n";
            inStack[st.top()] = false;
            st.pop();
        }
    }

public:
    Graph(int V) : V(V), adj(V), time(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void tarjanSCC() {
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;

        cout << "Tarjan's SCCs:\n";
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                sccHelper(i, disc, low, st, inStack);
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

    g.tarjanSCC();
    return 0;
}