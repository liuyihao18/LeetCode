// 2319_判断矩阵是否是一个X矩阵.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        size_t n = grid.size();
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                if ((i == j || i + j + 1 == n) && grid[i][j] == 0) 
                    return false;
                if (!(i == j || i + j + 1 == n) && grid[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
