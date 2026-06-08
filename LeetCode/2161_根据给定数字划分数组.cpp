// 2161_根据给定数字划分数组.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> results(nums.size());
        size_t left = 0, right = nums.size();
        for (int num : nums) {
            if (num < pivot) {
                results[left++] = num;
            }
        }
        for (int num : nums | views::reverse) {
            if (num > pivot) {
                results[--right] = num;
            }
        }
        for (; left < right; left++) {
            results[left] = pivot;
        }
        return results;
    }
};
