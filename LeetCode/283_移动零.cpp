// 283_“∆∂Ø¡„.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t slow = 0;
        for (size_t fast = 0; fast < nums.size(); fast++) {
            if (nums[fast]) {
                swap(nums[slow++], nums[fast]);
            }
        }
    }
};
