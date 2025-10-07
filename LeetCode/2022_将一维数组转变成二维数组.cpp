// 2022_将一维数组转变成二维数组.cpp
#include "stdafx.h"
ustd

#define _SIZE(x) static_cast<size_t>(x)

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != _SIZE(m) * _SIZE(n)) {
            return {};
        }
        /*
        vector<vector<int>> result(m, vector<int>(n, 0));
        size_t k = 0;
        for (size_t i = 0; i < _SIZE(m); i++) {
            vector<int>& row = result[i];
            for (size_t j = 0; j < _SIZE(n); j++) {
                row[j] = original[k++];
            }
        }
        */
        vector<vector<int>> result;
        for (auto iter = original.begin(); iter != original.end(); iter += n) {
            result.emplace_back(iter, iter + n);
        }
        return result;
    }
};
