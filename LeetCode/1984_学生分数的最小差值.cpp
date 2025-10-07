// 1984_学生分数的最小差值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        size_t i = 0;
        size_t j = k;
        j--;
        int min_diff = INT_MAX;
        while (j < nums.size()) {
            int min_num = nums[i];
            int max_num = nums[j];
            min_diff = min(min_diff, max_num - min_num);
            i++;
            j++;
        }
        return min_diff;
    }
};
