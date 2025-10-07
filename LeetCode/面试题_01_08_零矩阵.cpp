// √Ê ‘Ã‚_01_08_¡„æÿ’Û.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t m = matrix.size();
        if (m == 0) {
            return;
        }
        size_t n = matrix.front().size();
        if (n == 0) {
            return;
        }
        vector<size_t> rows, cols;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for (auto row : rows) {
            for (auto& elem : matrix[row]) {
                elem = 0;
            }
        }
        for (auto col : cols) {
            for (size_t i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
