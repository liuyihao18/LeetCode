// 3373_连接两棵树后最大目标节点数目_II.cpp
#include "custom.h"
ustd

class Solution {
    int bfs(const vector<vector<int>>& graph, int node, vector<int>& color) {
        size_t n = graph.size();
        vector<bool> visited(n, false);
        using State = pair<int, int>;
        queue<State> q;
        q.emplace(node, 0);
        int result = 0;
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            if (visited[curr.first]) {
                continue;
            }
            if (curr.second % 2 == 0) {
                result++;
                color[curr.first] = 0;
            }
            else {
                color[curr.first] = 1;
            }
            visited[curr.first] = true;
            for (int v : graph[curr.first]) {
                if (!visited[v]) {
                    q.emplace(v, curr.second + 1);
                }
            }
        }
        return result;
    }
    vector<vector<int>> toGraph(const vector<vector<int>>& edges) {
        size_t n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> graph1 = toGraph(edges1);
        vector<vector<int>> graph2 = toGraph(edges2);
        int n = static_cast<int>(graph1.size());
        int m = static_cast<int>(graph2.size());
        vector<int> color1(n, 0);
        vector<int> color2(m, 0);
        int black1 = bfs(graph1, 0, color1);
        int white1 = n - black1;
        int black2 = bfs(graph2, 0, color2);
        int white2 = m - black2;
        vector<int> results;
        for (int i = 0; i < n; i++) {
            if (color1[i] == 0) {
                results.push_back(black1);
            }
            else {
                results.push_back(white1);
            }
            results.back() += max(black2, white2);
        }
        return results;
    }
};
