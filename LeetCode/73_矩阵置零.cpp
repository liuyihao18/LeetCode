// 73_��������.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t m = matrix.size();
        if (m == 0) {
            return;
        }
        size_t n = matrix[0].size();
        if (n == 0) {
            return;
        }
        // ��һ�������в����ڵ���
        int target = 40001;
        for (; target < 40001 * 40001; target += 40001) {
            bool found = false;
            for (size_t i = 0; i < m; i++) {
                for (size_t j = 0; j < n; j++) {
                    if (matrix[i][j] == target) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        // ��һ�������ڵ�����ʾ0
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (size_t k = 0; k < n; k++) {
                        if (matrix[i][k] != 0) {
                            matrix[i][k] = target;
                        }
                    }
                    for (size_t k = 0; k < m; k++) {
                        if (matrix[k][j] != 0) {
                            matrix[k][j] = target;
                        }
                    }
                }
            }
        }
        // �Ѳ����ڵ����Ļ�0
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (matrix[i][j] == target) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
