// 1020_飞地的数量.cpp
#include "custom.h"
ustd

const int directions[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

class Solution {
    void _dfs(vector<vector<int>>& grid, size_t i, size_t j) {
        grid[i][j] = 0;
        for (auto direct : directions) {
            size_t new_i = i + direct[0];
            size_t new_j = j + direct[1];
            if (new_i != -1 && new_j != -1 && new_i < grid.size() && new_j < grid.front().size()) {
                if (grid[new_i][new_j]) {
                    _dfs(grid, new_i, new_j);
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0;
        size_t m = grid.size();
        size_t n = grid.front().size();
        for (size_t i = 0; i < m; i++) {
            if (grid[i][0]) {
                _dfs(grid, i, 0);
            }
            if (grid[i][n - 1]) {
                _dfs(grid, i, n - 1);
            }
        }
        for (size_t j = 0; j < n; j++) {
            if (grid[0][j]) {
                _dfs(grid, 0, j);
            }
            if (grid[m - 1][j]) {
                _dfs(grid, m - 1, j);
            }
        }
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j]) {
                    result++;
                }
            }
        }
        return result;
    }
};
