// 3372_连接两棵树后最大目标节点数目_I.cpp
#include "stdafx.h"
ustd

class Solution {
    int bfs(const vector<vector<int>>& graph, int node, int k) {
        size_t n = graph.size();
        vector<bool> visited(n, false);
        using State = pair<int, int>;
        queue<State> q;
        q.emplace(node, 0);
        int result = 0;
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            if (visited[curr.first] || curr.second > k) {
                continue;
            }
            result++;
            visited[curr.first] = true;
            for (int v : graph[curr.first]) {
                if (!visited[v] && curr.second < k) {
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
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> graph1 = toGraph(edges1);
        vector<vector<int>> graph2 = toGraph(edges2);
        int n = static_cast<int>(graph1.size());
        int m = static_cast<int>(graph2.size());
        int maxTargetNodes2 = 0;
        for (int i = 0; i < m; i++) {
            maxTargetNodes2 = max(maxTargetNodes2, bfs(graph2, i, k - 1));
        }
        vector<int> results;
        for (int i = 0; i < n; i++) {
            int maxTargetNodes1 = bfs(graph1, i, k);
            results.push_back(maxTargetNodes1 + maxTargetNodes2);
        }
        return results;
    }
};
