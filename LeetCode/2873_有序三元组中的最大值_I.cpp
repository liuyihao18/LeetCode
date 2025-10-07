// 2873_有序三元组中的最大值_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        size_t n = nums.size();
        long long result = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i + 1; j < n; j++) {
                for (size_t k = j + 1; k < n; k++) {
                    result = max(result, (0LL + nums[i] - nums[j]) * 1LL * nums[k]);
                }
            }
        }
        return result;
    }
};
