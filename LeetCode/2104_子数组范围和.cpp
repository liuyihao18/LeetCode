// 2104_子数组范围和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            int minimum = nums[i];
            int maximum = nums[i];
            for (size_t j = i + 1; j < nums.size(); j++) {
                minimum = min(minimum, nums[j]);
                maximum = max(maximum, nums[j]);
                result += static_cast<long long>(maximum) - static_cast<long long>(minimum);
            }
        }
        return result;
    }
};
