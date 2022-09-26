// 面试题_17_19_消失的两个数字.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        long long squareSum = accumulate(nums.begin(), nums.end(), 0LL,
            [](long long a, long long b) {
                return a + b * b;
            }
        );
        long long n = static_cast<long long>(nums.size() + 2);
        long long totalSum = (1 + n) * n / 2;
        long long totalSquareSum = 0;
        for (long long i = 1; i <= n; i++) {
            totalSquareSum += i * i;
        }
        long long a_b = totalSum - sum; // a + b
        long long a2_b2 = totalSquareSum - squareSum; // a^2 + b^2
        long long _2ab = a_b * a_b - a2_b2; // 2ab = (a + b)^2 - (a^2 + b^2)
        long long a__b = (long long)sqrt(a2_b2 - _2ab); // a - b = sqrt(a^2 + b^2 - 2ab)
        int a = (int)((a_b + a__b) / 2);
        int b = (int)(a_b - a);
        return { a,b };
    }
};
