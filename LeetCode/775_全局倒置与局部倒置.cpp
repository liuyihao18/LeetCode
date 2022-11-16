// 775_全局倒置与局部倒置.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};
