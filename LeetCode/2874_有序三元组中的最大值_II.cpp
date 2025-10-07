// 2874_������Ԫ���е����ֵ_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> dpMin(n, INT_MAX);  // dpMin[i]��ʾǰi�����Ĳ����Сֵ
        vector<int> dpMax(n, INT_MIN);  // dpMax[i]��ʾǰi�����Ĳ�����ֵ
        int leftMin = nums[0], leftMax = nums[0];
        for (size_t i = 2; i < nums.size(); i++) {
            dpMin[i] = min(dpMin[i - 1], leftMin - nums[i - 1]);
            dpMax[i] = max(dpMax[i - 1], leftMax - nums[i - 1]);
            leftMax = max(leftMax, nums[i - 1]);
            leftMin = max(leftMin, nums[i - 1]);
        }
        long long result = 0;
        for (size_t i = n - 1; i > 1; i--) {
            if (nums[i] > 0) {
                result = max(result, 1LL * nums[i] * dpMax[i]);
            }
            else {
                result = max(result, 1LL * nums[i] * dpMin[i]);
            }
        }
        return result;
    }
};
