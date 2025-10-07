// 2359_找到离给定两个节点最近的节点.cpp
#include "stdafx.h"
ustd

class Solution {
private:
    struct State {
        int node = 0;
        int distance = 0;
        State(int node, int distance) : node(node), distance(distance) {}
        bool operator<(const State& otherState) const {
            return distance > otherState.distance;
        }
    };
    vector<int> getDistance(const vector<int>& edge, int node) {
        int n = static_cast<int>(edge.size());
        vector<int> distance(n, -1);
        priority_queue<State> q;
        q.emplace(node, 0);
        while (!q.empty()) {
            State curr = q.top();
            q.pop();
            if (distance[curr.node] >= 0) {
                continue;
            }
            distance[curr.node] = curr.distance;
            if (edge[curr.node] >= 0) {
                q.emplace(edge[curr.node], curr.distance + 1);
            }
        }
        return distance;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> distance1 = getDistance(edges, node1);
        vector<int> distance2 = getDistance(edges, node2);
        int n = static_cast<int>(edges.size());
        int targetNode = -1;
        int targetDistance = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (distance1[i] >= 0 && distance2[i] >= 0) {
                int distance = max(distance1[i], distance2[i]);
                if (distance < targetDistance) {
                    targetDistance = distance;
                    targetNode = i;
                }
            }
        }
        return targetNode;
    }
};
