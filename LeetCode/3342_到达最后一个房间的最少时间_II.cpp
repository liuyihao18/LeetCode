// 3342_到达最后一个房间的最少时间_II.cpp
#include "custom.h"
ustd

class Solution {
    struct State {
        size_t i;
        size_t j;
        int time;
        int next_time;
        State(size_t i, size_t j, int time, int next_time) : i(i), j(j), time(time), next_time(next_time) {}
        bool operator<(const State& state) const {
            return time > state.time;
        }
    };
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        size_t m = moveTime.size(), n = moveTime.front().size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        vector<vector<int>> times(m, vector<int>(n, INT_MAX));
        const vector<pair<size_t, size_t>> directions = {
           {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        priority_queue<State> pq;
        pq.emplace(0, 0, 0, 1);
        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();
            if (curr.i + 1 == m && curr.j + 1 == n) {
                break;
            }
            if (visited[curr.i][curr.j]) {
                continue;
            }
            visited[curr.i][curr.j] = true;
            for (const pair<size_t, size_t>& direction : directions) {
                size_t new_i = curr.i + direction.first;
                size_t new_j = curr.j + direction.second;
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                    int new_time = max(curr.time, moveTime[new_i][new_j]) + curr.next_time;
                    if (new_time < times[new_i][new_j]) {
                        times[new_i][new_j] = new_time;
                        pq.emplace(new_i, new_j, new_time, 3 - curr.next_time);
                    }
                }
            }
        }
        return times[m - 1][n - 1];
    }
};
