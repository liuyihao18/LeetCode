// 2560_¥Úº“ΩŸ…·_IV.cpp
#include "custom.h"
ustd

class Solution {
    int maxSteal(vector<int>& nums, int target) {
        int k = 0;
        bool lastStolen = false;
        for (auto num : nums) {
            if (lastStolen) {
                lastStolen = false;
                continue;
            }
            else {
                if (num <= target) {
                    k++;
                    lastStolen = true;
                }
            }
        }
        return k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end()) + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (maxSteal(nums, mid) < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
