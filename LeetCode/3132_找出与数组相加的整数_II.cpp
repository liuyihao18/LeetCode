// 3132_找出与数组相加的整数_II.cpp
#include "custom.h"
ustd

class Solution {
    bool addedInteger(vector<int>& nums1, vector<int>& nums2, int& diff) {
        diff = nums2[0] - nums1[0];
        for (size_t i = 1; i < nums1.size(); i++) {
            if (diff != nums2[i] - nums1[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int minDiff = INT_MAX;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (size_t i = 0; i + 1 < nums1.size(); i++) {
            for (size_t j = i + 1; j < nums1.size(); j++) {
                vector<int> nums3;
                copy(nums1.begin(), nums1.begin() + i, back_inserter(nums3));
                copy(nums1.begin() + i + 1, nums1.begin() + j, back_inserter(nums3));
                copy(nums1.begin() + j + 1, nums1.end(), back_inserter(nums3));
                int diff = 0;
                if (addedInteger(nums3, nums2, diff)) {
                    minDiff = min(minDiff, diff);
                }
            }
        }
        return minDiff;
    }
};
