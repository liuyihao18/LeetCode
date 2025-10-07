// 1572_矩阵对角线元素的和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        size_t n = mat.size();
        int sum = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (i == j || i + j + 1 == n) {
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }
};
