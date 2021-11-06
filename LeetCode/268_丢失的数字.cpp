// 268_¶ªÊ§µÄÊý×Ö.cpp
#include "custom.h"
ustd

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int total_sum = (nums.size() * (nums.size() + 1)) / 2;
        return total_sum - sum;
    }
};