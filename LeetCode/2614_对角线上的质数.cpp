// 2614_对角线上的质数.cpp
#include "custom.h"
ustd

class Solution {
    bool isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        int n = static_cast<int>(sqrt(num));
        for (int i = 3; i <= n; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        size_t n = nums.size();
        int result = 0;
        for (size_t i = 0; i < n; i++) {
            if (isPrime(nums[i][i])) {
                result = max(result, nums[i][i]);
            }
            if (isPrime(nums[i][n - i - 1])) {
                result = max(result, nums[i][n - i - 1]);
            }
        }
        return result;
    }
};
