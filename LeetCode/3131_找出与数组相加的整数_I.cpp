// 3131_找出与数组相加的整数_I.cpp
#include "custom.h"
ustd

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        auto min1 = *min_element(nums1.begin(), nums1.end());
        auto min2 = *min_element(nums2.begin(), nums2.end());
        return min2 - min1;
    }
};
