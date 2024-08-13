// 3151_ÌØÊâÊı×é_I.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        adjacent_difference(nums.begin(), nums.end(), nums.begin(), plus<>());
        return all_of(nums.begin() + 1, nums.end(), [](int x) {
            return x & 1;
            });
    }
};
