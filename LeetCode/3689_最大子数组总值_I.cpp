// 3689_最大子数组总值_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long maxTotalValue(const vector<int>& nums, int k) {
        long long minValue = *ranges::min_element(nums);
        long long maxValue = *ranges::max_element(nums);
        return (maxValue - minValue) * k;
    }
};
