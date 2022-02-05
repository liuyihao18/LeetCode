// 1219_»Æ½ð¿ó¹¤.cpp
#include "custom.h"
ustd

const pair<int, int> directions[] = {
    { 0, 1 },
    { 1, 0 },
    { 0, -1 },
    { -1, 0 }
};

class Solution {
    int dfs(vector<vector<int>>& grid, size_t i, size_t j) {
        size_t m = grid.size();
        size_t n = grid.front().size();
        int temp = grid[i][j];
        grid[i][j] = 0;
        int result = 0;
        for (auto direct : directions) {
            size_t new_i = i + direct.first;
            size_t new_j = j + direct.second;
            if (new_i != -1 && new_i < m && new_j != -1 && new_j < n) {
                if (grid[new_i][new_j] > 0) {
                    result = max(result, dfs(grid, new_i, new_j));
                }
            }
        }
        grid[i][j] = temp;
        result += temp;
        return result;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        size_t m = grid.size();
        if (m == 0) {
            return 0;
        }
        size_t n = grid.front().size();
        if (n == 0) {
            return 0;
        }
        int result = 0;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    result = max(result, dfs(grid, i, j));
                }
            }
        }
        return result;
    }
};
