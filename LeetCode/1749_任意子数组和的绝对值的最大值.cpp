// 1749_任意子数组和的绝对值的最大值.cpp
#include "custom.h"
ustd

class Solution {
    int maxSum(const vector<int>& nums) {
        int dp = 0;
        int res = nums[0];
        for (auto num : nums) {
            dp = max(num, dp + num);
            res = max(dp, res);
        }
        return res;
    }
    int maxSum2(const vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0, maxSum = INT_MIN;
        while (j < nums.size()) { // [i, j]
            sum += nums[j];
            while (i < j && (sum < 0 || nums[i] < 0)) {
                sum -= nums[i];
                i++;
            }
            maxSum = max(sum, maxSum);
            j++;
        }
        return maxSum;
    }
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int pSum = maxSum(nums);
        for (auto& num : nums) {
            num = -num;
        }
        int nSum = maxSum(nums);
        return max(abs(pSum), abs(nSum));
    }
};
