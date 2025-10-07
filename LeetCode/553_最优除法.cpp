// 553_最优除法.cpp
#include "stdafx.h"
ustd

class Solution {
    string doDivision(vector<int>& nums, size_t i, size_t j, double& result, bool maximum) {
        if (j - i == 1) {
            result = nums[i] * 1.0;
            return to_string(nums[i]);
        }
        double dividend = 0;
        double divisor = 0;
        string _dividend;
        string _divisor;
        result = maximum ? 0 : INT_MAX;
        size_t max_l = 0;
        for (size_t l = 1; l < j - i; l++) {
            string temp1 = doDivision(nums, i, i + l, dividend, maximum);
            string temp2 = doDivision(nums, i + l, j, divisor, !maximum);
            if (maximum) {
                if (dividend / divisor > result) {
                    result = dividend / divisor;
                    _dividend = temp1;
                    _divisor = temp2;
                    max_l = l;
                }
            }
            else {
                if (dividend / divisor < result) {
                    result = dividend / divisor;
                    _dividend = temp1;
                    _divisor = temp2;
                    max_l = l;
                }
            }
        }
        if (max_l + 1 == j - i) {
            return _dividend + "/" + _divisor;
        }
        else {
            return _dividend + "/(" + _divisor + ")";
        }
    }
public:
    string optimalDivision(vector<int>& nums) {
        double _ = 0;
        return doDivision(nums, 0, nums.size(), _, true);
        // 虽然我也觉得是 num1 / (num2 / num3 / num4 / ...) 的形式结果最大来着，因为都是整数
    }
};
 