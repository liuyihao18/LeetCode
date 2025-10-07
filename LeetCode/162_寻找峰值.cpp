// 162_Ѱ�ҷ�ֵ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        size_t left = 0;
        size_t right = nums.size() - 1;
        size_t middle = -1;
        while (right > left) {
            middle = (left + right) >> 1;
            if (nums[middle] < nums[middle + 1]) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }
        return static_cast<int>(left);
    }
};