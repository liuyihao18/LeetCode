// 3142_判断矩阵是否满足条件.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        bool flag1 = all_of(grid.cbegin(), grid.cend(),
            [](const vector<int>& row) {
                for (size_t i = 0; i + 1 < row.size(); i++) {
                    if (row[i] == row[i + 1]) {
                        return false;
                    }
                }
                return true;
            }
        );
        vector<size_t> index(grid[0].size());
        iota(index.begin(), index.end(), 0);
        bool flag2 = all_of(index.cbegin(), index.cend(),
            [&](size_t j) {
                for (size_t i = 0; i + 1 < grid.size(); i++) {
                    if (grid[i][j] != grid[i + 1][j]) {
                        return false;
                    }
                }
                return true;
            }
        );
        return flag1 && flag2;
    }
};

// 优雅
/*
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        return ranges::count(grid, grid.front()) == grid.size() &&
            ranges::adjacent_find(grid.front()) == grid.front().end();
    }
};
*/
