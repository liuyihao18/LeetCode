// 667_优美的排列_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n, 1);
        for (int i = 1, diff = k, op = 1; diff; ++i, --diff, op *= -1) {
            result[i] = result[(size_t)i - 1] + diff * op;
        }
        iota(result.begin() + k + 1, result.end(), k + 2);
        return result;
    }
};
