// 1413_逐步求和得到正数的最小值.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minSum = 0;
        for (auto num : nums) {
            sum += num;
            minSum = min(sum, minSum);
        }
        return max(1 - minSum, 1);
    }
};
