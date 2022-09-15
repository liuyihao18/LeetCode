// 1619_删除某些元素后的数组均值.cpp
#include "custom.h"
ustd

class Solution {
public:
    double trimMean(vector<int>& arr) {
        size_t n = arr.size();
        sort(arr.begin(), arr.end());
        size_t n5 = n / 20;
        return accumulate(arr.begin() + n5, arr.end() - n5, 0.0) / (n - 2 * n5);
    }
};
