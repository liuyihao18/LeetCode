// 908_×îÐ¡²îÖµ_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_element = INT_MAX;
        int max_element = INT_MIN;
        for (auto num : nums) {
            min_element = min(min_element, num);
            max_element = max(max_element, num);
        }
        return max_element - min_element <= 2 * k ? 0 : max_element - min_element - 2 * k;
        // int min = *min_element(nums.begin(), nums.end());
        // int max = *max_element(nums.begin(), nums.end());
        // return max - min <= 2 * k ? 0 : max - min - 2 * k;
    }
};
