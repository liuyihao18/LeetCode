// 2908_元素和最小的山形三元组_I.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        return minimumSum1(nums);
    }

    int minimumSum1(vector<int>& nums) {
        vector<int> left = { INT_MAX };
        vector<int> right = { INT_MAX };
        for (auto iter = nums.begin(); iter + 1 != nums.end(); ++iter) {
            left.push_back(min(left.back(), *iter));
        }
        for (auto iter = nums.rbegin(); iter + 1 != nums.rend(); ++iter) {
            right.push_back(min(right.back(), *iter));
        }
        reverse(right.begin(), right.end());
        int minimumSum = INT_MAX;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > left[i] && nums[i] > right[i]) {
                minimumSum = min(minimumSum, nums[i] + left[i] + right[i]);
            }
        }
        return minimumSum == INT_MAX ? -1 : minimumSum;
    }

    int minimumSum2(vector<int>& nums) {
        int minimumSum = INT_MAX;
        for (size_t i = 0; i + 2 < nums.size(); i++) {
            for (size_t j = i + 1; j + 1 < nums.size(); j++) {
                for (size_t k = j + 1; k < nums.size(); k++) {
                    if (nums[i] < nums[j] && nums[k] < nums[j]) {
                        minimumSum = min(minimumSum, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        return minimumSum == INT_MAX ? -1 : minimumSum;
    }
};
