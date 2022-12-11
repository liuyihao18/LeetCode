// 1827_最少操作使数组递增.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                result += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return result;
    }
};
