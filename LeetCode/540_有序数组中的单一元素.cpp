// 540_有序数组中的单一元素.cpp
#include "custom.h"
ustd

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        size_t left = 0;
        size_t right = nums.size() - 1;
        while (right - left > 1) {
            size_t mid = (left + right) / 2;
            if (nums[mid] == nums[mid - 1]) {
                if (mid & 1) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
            else if (nums[mid] == nums[mid + 1]) {
                if (mid & 1) {
                    right = mid - 1;
                }
                else {
                    left = mid;
                }
            }
            else {
                return nums[mid];
            }
        }
        return nums[left];
    }
};
