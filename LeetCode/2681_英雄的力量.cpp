// 2681_Ó¢ÐÛµÄÁ¦Á¿.cpp
#include "custom.h"
ustd

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dp = 0, preSum = 0;
        int result = 0;
        int remainder = 1000000007;
        for (size_t i = 0; i < nums.size(); i++) {
            dp = (nums[i] + preSum) % remainder;
            preSum = (preSum + dp) % remainder;
            result = static_cast<int>((result + 1LL * nums[i] * nums[i] % remainder * dp)) % remainder;
            if (result < 0) {
                result += remainder;
            }
        }
        return result;
    }
};
