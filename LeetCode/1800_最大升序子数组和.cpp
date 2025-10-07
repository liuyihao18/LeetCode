// 1800_最大升序子数组和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        int lastNum = INT_MIN;
        for (auto num : nums) {
            if (num > lastNum) {
                sum += num;
            }
            else {
                maxSum = max(maxSum, sum);
                sum = num;
            }
            lastNum = num;
        }
        maxSum = max(maxSum, sum);
        return maxSum;
    }
};
