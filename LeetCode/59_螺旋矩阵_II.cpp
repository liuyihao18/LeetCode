// 59_ÂÝÐý¾ØÕó_II.cpp
#include "custom.h"
ustd

class Solution {
    void _generateMatrix(int& num, size_t pos, size_t len, vector<vector<int>>& matrix) {
        for (size_t j = 0; j < len; j++) {
            matrix[pos][pos + j] = num++;
        }
        for (size_t i = 1; i < len; i++) {
            matrix[pos + i][pos + len - 1] = num++;
        }
        for (size_t j = 1; j < len; j++) {
            matrix[pos + len - 1][pos + len - 1 - j] = num++;
        }
        for (size_t i = 1; i + 1 < len; i++) {
            matrix[pos + len - 1 - i][pos] = num++;
        }
    }
public:
    vector<vector<int>> generateMatrix(size_t n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;
        for (size_t i = 0; 2 * i < n; i++) {
            _generateMatrix(num, i, n - 2 * i, matrix);
        }
        return matrix;
    }
};
