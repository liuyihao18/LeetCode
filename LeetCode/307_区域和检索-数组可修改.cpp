// 307_区域和检索 - 数组可修改.cpp
#include "stdafx.h"
ustd

class NumArray {
    vector<int>& nums;
    vector<int> sums;
    int blockSize;
public:
    NumArray(vector<int>& nums) : nums(nums), blockSize(static_cast<int>(sqrt(nums.size()))) {
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if ((i + 1) % blockSize == 0) {
                sums.push_back(sum);
                sum = 0;
            }
        }
        sums.push_back(sum);
    }

    void update(int index, int val) {
        sums[index / blockSize] += val - nums[index];
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        if (right - left <= blockSize) {
            for (size_t i = left; i <= right; i++) {
                sum += nums[i];
            }
        }
        else {
            for (size_t i = (static_cast<size_t>(left) / blockSize) + 1; i < right / blockSize; i++) {
                sum += sums[i];
            }
            for (size_t i = left; i < min(((static_cast<size_t>(left) / blockSize) + 1) * blockSize, nums.size()); i++) {
                sum += nums[i];
            }
            for (size_t i = (static_cast<size_t>(right) / blockSize) * blockSize; i <= right; i++) {
                sum += nums[i];
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
