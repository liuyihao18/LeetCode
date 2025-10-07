// 1403_非递增顺序的最小子序列.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result{ nums.back() };
        nums.pop_back();
        int sum = accumulate(result.begin(), result.end(), 0);
        int remain = accumulate(nums.begin(), nums.end(), 0);
        while (sum <= remain) {
            result.push_back(nums.back());
            sum += nums.back();
            remain -= nums.back();
            nums.pop_back();
        }
        return result;
    }
};
