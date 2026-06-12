// 3559_给边赋权值的方案数_II.cpp
#include "stdafx.h"
ustd

// 需要使用倍增数组快速查找公共祖先，否则退化成单链的情况下会TLE
class Solution {
    static int quickPow(int x, int n, int module) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x % module;
        }
        long long half = quickPow(x, n / 2, module);
        if (n & 1) {
            return (half * half * x) % module;
        }
        else {
            return (half * half) % module;
        }
    }
    static void computeAncestorsAndDepth(const vector<vector<int>>& graph, vector<int>& parents, vector<int>& depths) {
        parents[0] = 0;
        stack<pair<int, int>> st;
        st.emplace(0, 0);
        while (!st.empty()) {
            const auto [u, depth] = st.top();
            st.pop();
            depths[u] = depth;
            for (const int v : graph[u]) {
                parents[v] = u;
                st.emplace(v, depth + 1);
            }
        }
    }
    static int findLowestCommonAncestor(const vector<int>& parents, const vector<int>& depth, int node1, int node2) {
        while (depth[node1] > depth[node2]) {
            node1 = parents[node1];
        }
        while (depth[node1] < depth[node2]) {
            node2 = parents[node2];
        }
        while (node1 != node2) {
            node1 = parents[node1];
            node2 = parents[node2];
        }
        return node1;
    }
public:
    vector<int> assignEdgeWeights(const vector<vector<int>>& edges, const vector<vector<int>>& queries) {
        const int n = static_cast<int>(edges.size()) + 1;
        vector<vector<int>> graph(n);
        for (const vector<int>& edge : edges) {
            const int u = edge[0] - 1;
            const int v = edge[1] - 1;
            graph[u].push_back(v);
        }
        
        vector<int> parents(n);
        vector<int> depth(n);
        computeAncestorsAndDepth(graph, parents, depth);
        
        vector<int> results;
        for (const vector<int>& query : queries) {
            const int node1 = query[0] - 1;
            const int node2 = query[1] - 1;
            const int ancestor = findLowestCommonAncestor(parents, depth, node1, node2);
            const int length = depth[node1] + depth[node2] - 2 * depth[ancestor];
            results.push_back(quickPow(2, length - 1, static_cast<int>(1e9 + 7)));
        }
        
        return results;
    }
};
