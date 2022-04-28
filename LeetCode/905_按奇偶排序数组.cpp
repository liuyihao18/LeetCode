// 905_°´ÆæÅ¼ÅÅĞòÊı×é.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        for (size_t i = 0, j = nums.size() - 1; i < j;) {
            while (i < j && !(nums[i] & 1)) {
                i++;
            }
            while (i < j && (nums[j] & 1)) {
                j--;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
