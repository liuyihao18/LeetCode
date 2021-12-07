// 1034_±ß½ç×ÅÉ«.cpp
#include "custom.h"
ustd

#define CURR(row, col) [static_cast<size_t>(row)][static_cast<size_t>(col)]
#define UP(row, col) [static_cast<size_t>(row) - 1][static_cast<size_t>(col)]
#define DOWN(row, col) [static_cast<size_t>(row) + 1][static_cast<size_t>(col)]
#define LEFT(row, col) [static_cast<size_t>(row)][static_cast<size_t>(col) - 1]
#define RIGHT(row, col) [static_cast<size_t>(row)][static_cast<size_t>(col) + 1]

class Solution {
    set<pair<size_t, size_t>> borders;
    bool isBorder(const vector<vector<int>>& grid, int row, int col) {
        if (row < 1 || row >= static_cast<int>(grid.size()) - 1 || col < 1 || col >= static_cast<int>(grid.front().size()) - 1) {
            return true;
        }
        if (grid UP(row, col) == grid CURR(row, col) && 
            grid DOWN(row, col) == grid CURR(row, col) && 
            grid LEFT(row, col) == grid CURR(row, col) && 
            grid RIGHT(row, col) == grid CURR(row, col)) {
            return false;
        }
        return true;
    }
    void _dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (visited CURR(row, col)) {
            return;
        }
        visited CURR(row, col) = true;
        if (isBorder(grid, row, col)) {
            borders.insert({ row,col });
        }
        if (row >= 1 && grid CURR(row, col) == grid UP(row, col)) {
            _dfs(grid, visited, row - 1, col); // UP
        }
        if (row < static_cast<int>(grid.size()) - 1 && grid CURR(row, col) == grid DOWN(row, col)) {
            _dfs(grid, visited, row + 1, col); // DOWN
        }
        if (col >= 1 && grid CURR(row, col) == grid LEFT(row, col)) {
            _dfs(grid, visited, row, col - 1); // LEFT
        }
        if (col < static_cast<int>(grid.front().size()) - 1 && grid CURR(row, col) == grid RIGHT(row, col)) {
            _dfs(grid, visited, row, col + 1); // RIGHT
        }
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if (grid.empty()) {
            return { {} };
        }
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.front().size()));
        _dfs(grid, visited, row, col);
        for (const auto &border : borders) {
            grid CURR(border.first, border.second) = color;
        }
        return grid;
    }
};
