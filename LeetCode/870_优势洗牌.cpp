// 870_”≈ ∆œ¥≈∆.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        vector<size_t> index2(nums2.size());
        iota(index2.begin(), index2.end(), 0);
        sort(index2.begin(), index2.end(), [&](size_t i1, size_t i2) {
            return nums2[i1] > nums2[i2];
            });
        vector<int> result(nums1.size());
        for (size_t i = 0, j = 0, k = result.size() - 1; i < result.size(); i++) {
            size_t i2 = index2[i];
            if (nums1[k] > nums2[i2]) {
                result[i2] = nums1[k];
                k--;
            }
            else {
                result[i2] = nums1[j];
                j++;
            }
        }
        return result;
    }
};
