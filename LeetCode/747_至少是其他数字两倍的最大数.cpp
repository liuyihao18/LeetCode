// 747_至少是其他数字两倍的最大数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int dominantIndex(const vector<int>& nums) {
        auto iter = max_element(nums.begin(), nums.end());
        return all_of(nums.begin(), nums.end(), [=](int num) {
            return *iter == num ||*iter >= 2 * num;
            }) ? static_cast<int>(distance(nums.begin(), iter)) : -1;
    }
};
