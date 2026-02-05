// 3379_×ª»»Êý×é.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size());
        for (int i{}, n{ static_cast<int>(nums.size()) }; 
            i < n; i++) {
            const int j = ((i + nums[i]) % n + n) % n;
            result[i] = nums[j];
        }
        return result;
    }
};
