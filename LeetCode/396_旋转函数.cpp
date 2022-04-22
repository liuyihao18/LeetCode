// 396_Ðý×ªº¯Êý.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int F = 0;
        for (int i = 0; i < n; i++) {
            F += i * nums[i];
        }
        int MAX_F = F;
        for (int k = 1; k < n; k++) {
            F = F + sum - nums[static_cast<size_t>(n - k)] * n;
            MAX_F = max(MAX_F, F);
        }
        return MAX_F;
    }
};
