// 2154_将找到的值乘以2.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        while (true) {
            vector<int>::iterator iter = lower_bound(nums.begin(), nums.end(), original);
            if (iter == nums.end() || *iter != original) {
                break;
            }
            original *= 2;
        }
        return original;
    }
};
