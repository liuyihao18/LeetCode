// 219_�����ظ�Ԫ��_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, size_t> numsIndex;
        for (size_t i = 0; i < nums.size(); i++) {
            auto iter = numsIndex.find(nums[i]);
            if (iter != numsIndex.end()) {
                if (i - iter->second <= k) {
                    return true;
                }
            }
            numsIndex[nums[i]] = i;
        }
        return false;
    }
};
