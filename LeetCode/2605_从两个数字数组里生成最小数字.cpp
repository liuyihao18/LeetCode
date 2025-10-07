// 2605_从两个数字数组里生成最小数字.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto iter1 = nums1.begin(), iter2 = nums2.begin();
        int result = INT_MAX;
        while (iter1 != nums1.end() && iter2 != nums2.end()) {
            int temp;
            if (*iter1 == *iter2) {
                temp = *iter1;
                iter1++;
                iter2++;
            }
            else if (*iter1 < *iter2) {
                temp = 10 * *iter1 + *iter2;
                iter1++;
            }
            else {
                temp = 10 * *iter2 + *iter1;
                iter2++;
            }
            result = min(result, temp);
        }
        return result;
    }
};
