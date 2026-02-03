// 3637_三段式数组_I.cpp
#include "stdafx.h"
ustd

class Solution {
    size_t checkIncrease(const vector<int>& nums, size_t i) {
        for (size_t n{ nums.size() }; i + 1 < n && nums[i] < nums[i + 1]; i++);
        return i;
    }
    size_t checkDecrease(const vector<int>& nums, size_t i) {
        for (size_t n{ nums.size() }; i + 1 < n && nums[i] > nums[i + 1]; i++);
        return i;
    }
public:
    bool isTrionic(vector<int>& nums) {
        size_t i{}, j{};
        j = checkIncrease(nums, i);
        if (i == j || j + 1 == nums.size()) return false;
        i = j;
        j = checkDecrease(nums, i);
        if (i == j || j + 1 == nums.size()) return false;
        i = j;
        j = checkIncrease(nums, i);
        if (i == j) return false;
        return j + 1 == nums.size();
    }
};
