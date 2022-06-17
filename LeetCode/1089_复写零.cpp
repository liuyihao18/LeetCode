// 1089_∏¥–¥¡„.cpp
#include "custom.h"
ustd

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        size_t n = arr.size();
        for (auto iter = arr.begin(); iter < arr.begin() + n && iter != arr.end(); ++iter) {
            if (*iter == 0) {
                iter = ++arr.insert(iter, 0);
            }
        }
        arr.resize(n);
    }
};
