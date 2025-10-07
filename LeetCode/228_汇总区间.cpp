// 228_»ã×ÜÇø¼ä.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        long long last = nums[0] - 1LL, left = nums[0];
        vector<string> result;
        for (auto num : nums) {
            if (num != last + 1) {
                if (left == last) {
                    result.push_back(to_string(left));
                }
                else {
                    result.push_back(to_string(left) + "->" + to_string(last));
                }
                left = num;
            }
            last = num;
        }
        if (left == last) {
            result.push_back(to_string(left));
        }
        else {
            result.push_back(to_string(left) + "->" + to_string(last));
        }
        return result;
    }
};
