// 1748_唯一元素的和.cpp
#include "custom.h"
ustd

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> counts(101, 0);
        for (auto num : nums) {
            counts[num]++;
        }
        int result = 0;
        for (size_t i = 0; i < counts.size(); i++) {
            if (counts[i] == 1) {
                result += static_cast<int>(i);
            }
        }
        return result;
    }
};
