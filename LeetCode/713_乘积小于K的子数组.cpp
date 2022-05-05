// 713_�˻�С��K��������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0;
        int prod = 1;
        // ��������
        for (size_t i = 0, j = 0; j < nums.size(); j++) {
            prod *= nums[j];
            while (i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            result += static_cast<int>(j - i + 1);
        }
        return result;
    }
};
