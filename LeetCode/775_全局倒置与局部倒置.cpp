// 775_ȫ�ֵ�����ֲ�����.cpp
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
