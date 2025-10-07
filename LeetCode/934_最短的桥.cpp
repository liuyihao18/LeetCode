// 934_×î¶ÌµÄÇÅ.cpp
#include "stdafx.h"
ustd

class Solution {
    void dfs(size_t i, size_t j, vector<vector<int>>& grid, queue<pair<size_t, size_t>>& q) {
        const int dirs[][2] = {
            {-1,  0},
            { 1,  0},
            { 0,  1},
            { 0, -1}
        };
        q.emplace(i, j);
        grid[i][j] = -grid[i][j];
        size_t m = grid.size(), n = grid[0].size();
        for (auto dir : dirs) {
            size_t new_i = i + dir[0];
            size_t new_j = j + dir[1];
            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1) {
                dfs(new_i, new_j, grid, q);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid[0].size();
        size_t first_i = 0, first_j = 0;
        for (size_t i = 0; i < m; i++) {
            bool found = false;
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    first_i = i;
                    first_j = j;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        queue<pair<size_t, size_t>> q;
        dfs(first_i, first_j, grid, q);
        while (!q.empty()) {
            pair<size_t, size_t> curr = q.front();
            q.pop();
            const int dirs[][2] = {
                {-1,  0},
                { 1,  0},
                { 0,  1},
                { 0, -1}
            };
            int next_steps = grid[curr.first][curr.second] - 1;
            for (auto dir : dirs) {
                size_t new_i = curr.first + dir[0];
                size_t new_j = curr.second + dir[1];
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                    if (grid[new_i][new_j] == 1) {
                        return -next_steps - 2;
                    }
                    else if (grid[new_i][new_j] == 0) {
                        grid[new_i][new_j] = next_steps;
                        q.emplace(new_i, new_j);
                    }
                }
            }
        }
        return -1;
    }
};
