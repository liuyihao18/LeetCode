// 2563_统计公平数对的数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        long long result = 0;
        for (size_t k = 1; k < n; k++) {
            size_t i = lower_bound(nums.begin(), nums.begin() + k, lower - nums[k]) - nums.begin();
            size_t j = upper_bound(nums.begin(), nums.begin() + k, upper - nums[k]) - nums.begin();
            result += static_cast<long long>(j - i);
        }
        return result;
    }
};
