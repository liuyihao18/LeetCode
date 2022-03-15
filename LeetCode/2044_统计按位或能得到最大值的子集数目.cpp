// 2044_统计按位或能得到最大值的子集数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        size_t total = static_cast<size_t>(1) << nums.size();
        int count = 0;
        int maxResult = 0;
        for (size_t i = 1; i < total; i++) {
            int result = 0;
            for (size_t j = 0; j < nums.size(); j++) {
                if (static_cast<size_t>(1) << j & i) {
                    result |= nums[j];
                }
            }
            if (result > maxResult) {
                maxResult = result;
                count = 1;
            }
            else if (result == maxResult) {
                count++;
            }
        }
        return count;
    }
};
