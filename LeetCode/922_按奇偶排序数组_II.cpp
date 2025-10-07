// 922_°´ÆæÅ¼ÅÅÐòÊý×é_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        size_t i = 0, j = 1, n = nums.size();
        while (i < n && j < n) {
            if (nums[i] % 2 == 0) {
                i += 2;
                continue;
            }
            if (nums[j] % 2 == 1) {
                j += 2;
                continue;
            }
            swap(nums[i], nums[j]);
            i += 2;
            j += 2;
        }
        return nums;
    }
};
