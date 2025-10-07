// 3396_使数组元素互不相同所需的最少操作次数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        size_t n = nums.size();
        int removeCount = 0;
        vector<int> counts(105, 0);
        for (size_t i = n - 1; i != -1; i--) {
            if (counts[nums[i]] > 0) {
                removeCount = static_cast<int>(i + 1);
                break;
            }
            else {
                counts[nums[i]]++;
            }
        }
        return (removeCount + 2) / 3;
    }
};
