// 673_最长递增子序列的个数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<size_t> length(nums.size(), 1);
        vector<size_t> counts(nums.size(), 1);
        size_t max_length{ 1 };
        size_t max_count{ 1 };
        for (size_t i = 1; i < nums.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (length[i] < length[j] + 1) {
                        length[i] = length[j] + 1;
                        counts[i] = counts[j];
                    }
                    else if (length[i] == length[j] + 1) {
                        length[i] = length[j] + 1;
                        counts[i] += counts[j];
                    }
                }
            }
            if (length[i] > max_length) {
                max_length = length[i];
                max_count = counts[i];
            }
            else if (length[i] == max_length) {
                max_count += counts[i];
            }
        }
        return static_cast<int>(max_count);
    }
};