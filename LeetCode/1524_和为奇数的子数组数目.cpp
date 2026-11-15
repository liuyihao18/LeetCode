// 1524_和为奇数的子数组数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const size_t n = arr.size();
        // even = dp[i].first 为以 i 结尾的、和为偶数的子数组数量
        // even = dp[i].second 为以 i 结尾的、和为奇数的子数组数量
        int even = 0, odd = 0;
        constexpr int remainder = static_cast<int>(1e9 + 7);
        int result = 0;
        for (const int num : arr) {
            if (num & 1) {
                const int temp = even;
                even = odd;      // dp[i].first = dp[i - 1].second;
                odd = temp + 1;  // dp[i].second = dp[i - 1].first + 1;
            }
            else {
                odd = odd;       // dp[i].first = dp[i - 1].first + 1;
                even = even + 1; // dp[i].second = dp[i - 1].second;
            }
            result = (result + odd) % remainder;
        }
        return result;
    }
};
