// 1413_����͵õ���������Сֵ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minSum = 0;
        for (auto num : nums) {
            sum += num;
            minSum = min(sum, minSum);
        }
        return max(1 - minSum, 1);
    }
};
