// 3127_构造相同颜色的正方形.cpp
#include "stdafx.h"
ustd

class Solution {
    bool checkSquare(const vector<vector<char>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        for (size_t i = 0; i + 1 < m; i++) {
            for (size_t j = 0; j + 1 < n; j++) {
                auto temp = { grid[i][j], grid[i + 1][j], grid[i][j + 1], grid[i + 1][j + 1] };
                if (all_of(temp.begin(), temp.end(),
                    [&](char c) {
                        return c == grid[i][j];
                    }
                )) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        if (checkSquare(grid)) {
            return true;
        }
        size_t m = grid.size();
        size_t n = grid[0].size();
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                auto temp = grid[i][j];
                if (grid[i][j] == 'B') {
                    grid[i][j] = 'W';
                }
                else {
                    grid[i][j] = 'B';
                }
                if (checkSquare(grid)) {
                    return true;
                }
                grid[i][j] = temp;
            }
        }
        return false;
    }
};
