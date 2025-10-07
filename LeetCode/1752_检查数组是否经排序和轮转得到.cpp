// 1752_检查数组是否经排序和轮转得到.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> origin = nums;
        sort(origin.begin(), origin.end());
        for (size_t offset = 0; offset < nums.size(); offset++) {
            size_t i = 0;
            for (; i < nums.size(); i++) {
                if (nums[i] != origin[(i + offset) % nums.size()]) {
                    break;
                }
            }
            if (i == nums.size()) {
                return true;
            }
        }
        return false;
    }
};
