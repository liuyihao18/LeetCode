// 882_细分图中的可到达节点.cpp
#include "custom.h"
ustd

class Solution {
public:
    int encode(int u, int v, int n) {
        return u * n + v;
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adList(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], nodes = edge[2];
            adList[u].emplace_back(v, nodes);
            adList[v].emplace_back(u, nodes);
        }

        unordered_map<int, int> used;
        unordered_set<int> visited;
        int reachableNodes = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        while (!pq.empty() && pq.top().first <= maxMoves) {
            auto [step, u] = pq.top();
            pq.pop();
            if (visited.count(u)) {
                continue;
            }
            visited.emplace(u);
            reachableNodes++;
            for (auto [v, nodes] : adList[u]) {
                if (nodes + step + 1 <= maxMoves && !visited.count(v)) {
                    pq.emplace(nodes + step + 1, v);
                }
                used[encode(u, v, n)] = min(nodes, maxMoves - step);
            }
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], nodes = edge[2];
            reachableNodes += min(nodes, used[encode(u, v, n)] + used[encode(v, u, n)]);
        }
        return reachableNodes;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/reachable-nodes-in-subdivided-graph/solutions/1990614/xi-fen-tu-zhong-de-ke-dao-da-jie-dian-by-u8m1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
