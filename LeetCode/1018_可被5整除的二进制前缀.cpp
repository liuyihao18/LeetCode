// 1018_可被5整除的二进制前缀.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int sum = 0;
        vector<bool> result;
        transform(nums.begin(), nums.end(), back_inserter(result),
            [&](int num) {
                sum = (sum * 2 + num) % 5;
                return sum == 0;
            });
        return result;
    }
};
