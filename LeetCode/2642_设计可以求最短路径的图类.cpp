#include "custom.h"
ustd

class Graph {
public:
    using pii = pair<int, int>;
    Graph(int n, vector<vector<int>>& edges) : n(n), g(n) {
        for (const auto& edge : edges) {
            addEdge(edge);
        }
    }

    void addEdge(const vector<int>& edge) {
        auto u = edge[0];
        auto v = edge[1];
        auto c = edge[2];
        g[u].emplace_back(v, c);
    }

    int shortestPath(int node1, int node2) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        pq.emplace(0, node1);
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (u == node2) {
                return cost;
            }
            for (auto [v, c] : g[u]) {
                if (dist[v] > dist[u] + c) {
                    dist[v] = dist[u] + c;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return -1;
    }
private:
    int n;
    vector<vector<pii>> g;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
