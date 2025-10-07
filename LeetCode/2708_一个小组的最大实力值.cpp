// 2708_一个小组的最大实力值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long strength = LLONG_MIN;
        for (int i = 1; i < 1 << nums.size(); i++) {
            long long temp = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i >> j & 1) {
                    temp *= nums[j];
                }
            }
            strength = max(strength, temp);
        }
        return strength;
    }
};

