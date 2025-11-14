// 2536_×Ó¾ØÕóÔªËØ¼Ó1.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));
        for (const vector<int>& query : queries) {
            size_t row1 = query[0];
            size_t col1 = query[1];
            size_t row2 = query[2];
            size_t col2 = query[3];
            for (size_t i = row1; i <= row2; i++) {
                diff[i][col1]++;
                if (col2 + 1 < n) {
                    diff[i][col2 + 1]--;
                }
            }
        }
        vector<vector<int>>& result = diff;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 1; j < n; j++) {
                result[i][j] = result[i][j - 1] + diff[i][j];
            }
        }
        return result;
    }
};
