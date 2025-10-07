// 324_°Ú¶¯ÅÅÐò_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        size_t i = (temp.size() - 1) / 2, j = temp.size() - 1;
        size_t k = 0;
        while (k < nums.size()) {
            if (k < nums.size()) {
                nums[k++] = temp[i--];
            }
            if (k < nums.size()) {
                nums[k++] = temp[j--];
            }
        }
    }
};
