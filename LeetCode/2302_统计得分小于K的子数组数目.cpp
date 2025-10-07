// 2302_ͳ�Ƶ÷�С��K����������Ŀ.cpp
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
            result += j - i; // ���� [i, j)���� j - 1 ��β��������������� j - i
        }
        return result;
    }
};
