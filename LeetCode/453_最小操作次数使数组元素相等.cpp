// 453_最小操作次数使数组元素相等.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = *min_element(nums.begin(), nums.end());
        int result = 0;
        for (auto num : nums) {
            result += num - min_num;
        }
        return result;
    }
};