// 2680_最大或值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        size_t n = nums.size();
        vector<long long> prefixOr(n, 0);
        vector<long long> suffixOr(n, 0); 
        for (size_t i = 1; i != n; i++) {
            prefixOr[i] = prefixOr[i - 1] | nums[i - 1];
        }
        for (size_t i = n - 2; i != -1; i--) {
            suffixOr[i] = suffixOr[i + 1] | nums[i + 1];
        }
        long long result = 0;
        for (size_t i = 0; i != n; i++) {
            result = max(result, prefixOr[i] | suffixOr[i] | static_cast<long long>(nums[i]) << k);
        }
        return result;
    }
};
