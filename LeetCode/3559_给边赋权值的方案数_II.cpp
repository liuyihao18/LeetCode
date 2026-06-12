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
    static void computeParentsAndDepth(
        const int u, const vector<vector<int>>& graph,
        vector<vector<int>>& parents, vector<int>& depth,
        vector<int>& tempPath, vector<bool>& visited) 
    {
        visited[u] = true;
        // 倍增祖先
        int pIndex = static_cast<int>(tempPath.size() - 1);
        int index = 0;
        while (pIndex >= 0) {
            parents[u].push_back(tempPath[pIndex]);
            pIndex -= 1 << index;
            index++;
        }
        // 计算深度
        if (parents[u].size() == 0) {
            depth[u] = 0;
        }
        else {
            depth[u] = depth[parents[u][0]] + 1;
        }
        // DFS
        for (const int v : graph[u]) {
            if (visited[v]) {
                continue;
            }
            tempPath.push_back(u);
            computeParentsAndDepth(v, graph, parents, depth, tempPath, visited);
            tempPath.pop_back();
        }
    }
    static int findLowestCommonAncestor(const vector<vector<int>>& parents, const vector<int>& depth, int node1, int node2) {
        // 快速跳跃对齐高度
        while (depth[node1] > depth[node2]) {
            const int jump = static_cast<int>(log2(depth[node1] - depth[node2]));
            node1 = parents[node1][jump];
        }
        while (depth[node1] < depth[node2]) {
            const int jump = static_cast<int>(log2(depth[node2] - depth[node1]));
            node2 = parents[node2][jump];
        }
        while (node1 != node2) {
            node1 = parents[node1][0];
            node2 = parents[node2][0];
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
            graph[v].push_back(u);
        }
        
        vector<vector<int>> parents(n);
        vector<int> depth(n);
        vector<int> tempPath;
        vector<bool> visited(n);
        computeParentsAndDepth(0, graph, parents, depth, tempPath, visited);
        
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

/*
int main() {
    vector<vector<int>> edges = {
        {3,2},{2,1}
    };
    vector<vector<int>> queries = {
        {3,1}
    };
    vector<int> results = Solution().assignEdgeWeights(edges, queries);
    for (const int result : results) {
        cout << result << " ";
    }
    cout << endl;
    return 0;
}
*/
