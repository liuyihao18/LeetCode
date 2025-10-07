// 3341_到达最后一个房间的最少时间_I.cpp
#include "stdafx.h"
ustd

class Solution {
    struct State {
        size_t i;
        size_t j;
        int time;
        State(size_t i, size_t j, int time) : i(i), j(j), time(time) {}
        bool operator<(const State& state) const {
            return time > state.time;
        }
    };
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        size_t m = moveTime.size(), n = moveTime.front().size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        const vector<pair<size_t, size_t>> directions = {
           {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        priority_queue<State> pq;
        pq.emplace(0, 0, 0);
        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();
            if (curr.i + 1 == m && curr.j + 1 == n) {
                return curr.time;
            }
            if (visited[curr.i][curr.j]) {
                continue;
            }
            visited[curr.i][curr.j] = true;
            for (const pair<size_t, size_t>& direction : directions) {
                size_t new_i = curr.i + direction.first;
                size_t new_j = curr.j + direction.second;
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                    pq.emplace(new_i, new_j, max(curr.time + 1, moveTime[new_i][new_j] + 1));
                }
            }
        }
        return -1;
    }
};
