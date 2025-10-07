// 2845_统计趣味子数组的数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        size_t n = nums.size();
        int prefixSum = 0;
        unordered_map<int, int> counts;
        counts[0] = 1;
        long long result = 0;
        for (size_t i = 0; i < n; i++) {
            if (nums[i] % modulo == k) {
                prefixSum++;
            }
            if (counts.count((prefixSum - k + modulo) % modulo)) {
                result += counts[(prefixSum - k + modulo) % modulo];
            }
            counts[prefixSum % modulo]++;
        }
        return result;     
    }
};
