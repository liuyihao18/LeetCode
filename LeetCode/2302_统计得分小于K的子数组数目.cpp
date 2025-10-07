// 2302_统计得分小于K的子数组数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long i = 0, j = 0;
        long long sum = 0;
        long long result = 0;
        while (j < n) {
            sum += nums[j++];
            while (i <= j && sum * (j - i) >= k) {
                sum -= nums[i++];
            }
            result += j - i; // 区间 [i, j)，以 j - 1 结尾的子数组的数量是 j - i
        }
        return result;
    }
};
