// 53_����������.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t n = nums.size();
        int result = INT_MIN;
        int sum = 0;
        // dp[i] ��ʾ�� nums[i] ��β�������������
        // dp[i] = max{dp[i - 1] + nums[i], nums[i]};
        for (size_t i = 0; i < n; i++) {
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};

/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t i = 0, j = 0;
        int sum = 0, maxSum = INT_MIN;
        while (j < nums.size()) {
            sum += nums[j++];
            maxSum = max(maxSum, sum);
            while (sum < 0 && i < j) {
                sum -= nums[i++];
            }
        }
        return maxSum;
    }
};
*/
