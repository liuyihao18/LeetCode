// 198_¥Úº“ΩŸ…·.cpp
#include "custom.h"
ustd

class Solution {
public:
    int rob(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for (auto num : nums) {
            int temp1 = max1, temp2 = max2;
            max1 = max(temp1, temp2);
            max2 = temp1 + num;
        }
        return max(max1, max2);
    }
};
