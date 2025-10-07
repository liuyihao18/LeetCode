// 2529_正整数和负整数的最大计数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for (auto num : nums) {
            if (num > 0) {
                pos++;
            }
            else if (num < 0) {
                neg++;
            }
        }
        return pos > neg ? pos : neg;
    }
};
