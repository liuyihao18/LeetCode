// 1822_数组元素积的符号.cpp
#include "custom.h"
ustd

class Solution {
public:
    int arraySign(vector<int>& nums) {
        unsigned result = 0;
        for (auto num : nums) {
            if (num == 0) return 0;
            result ^= static_cast<unsigned>(num) >> 31;
        }
        return result == 1 ? -1 : 1;
    }
};
