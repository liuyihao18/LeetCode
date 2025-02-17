// 1287_有序数组中出现次数超过25%的元素.cpp
#include "custom.h"
ustd

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        size_t n = arr.size();
        size_t step = n / 4 - 1;
        for (size_t i = 0; i < n; i+=step) {
            auto left = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto right = upper_bound(arr.begin(), arr.end(), arr[i]);
            size_t cnt = distance(left, right);
            if (4 * cnt > n) {
                return arr[i];
            }
        }
        return 0;
    }
};
