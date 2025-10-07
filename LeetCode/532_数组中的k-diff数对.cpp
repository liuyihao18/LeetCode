// 532_数组中的k-diff数对.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (size_t i = 0, j = 1; j < nums.size();) {
            while (j < nums.size() && (j <= i || nums[j] - nums[i] < k)) {
                j++;
            }
            if (j < nums.size() && nums[j] - nums[i] == k) {
                count++;
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                    i++;
                }
                i++;
                while (j + 1 < nums.size() && nums[j + 1] == nums[j]) {
                    j++;
                }
                j++;
            }
            else {
                i++;
            }
        }
        return count;
    }
};
