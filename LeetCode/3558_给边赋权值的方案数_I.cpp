// 3558_给边赋权值的方案数_I.cpp
#include "stdafx.h"
ustd

class Solution {
    static int getMaxDepth(const vector<vector<int>>& graph) {
        stack<pair<int, int>> st;
        st.emplace(0, 0);
        int maxDepth = 0;
        while (!st.empty()) {
            auto [u, depth] = st.top();
            st.pop();
            maxDepth = max(maxDepth, depth);
            for (const int v : graph[u]) {
                st.emplace(v, depth + 1);
            }
        }
        return maxDepth;
    }
    static int quickPow(int x, int n, int module) {
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
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int n = static_cast<int>(edges.size()) + 1;
        vector<vector<int>> graph(n);
        for (const vector<int>& edge : edges) {
            const int u = edge[0] - 1;
            const int v = edge[1] - 1;
            graph[u].push_back(v);
        }
        const int maxDepth = getMaxDepth(graph);
        // dp[n][0] 表示n个数的和为偶数
        // dp[n][1] 表示n个数的和为奇数
        // dp[n][0] = dp[n-1][0] + dp[n-1][1]
        // dp[n][1] = dp[n-1][0] + dp[n-1][1]
        // dp[1][0] = 1; // 0
        // dp[2][0] = 2; // (0,0)、(1,1)
        // dp[3][0] = 4; // (0,1,1)、(1,1,0)、(1,0,1)、(0,0,0)
        return quickPow(2, maxDepth - 1, static_cast<int>(1e9 + 7));
    }
};
