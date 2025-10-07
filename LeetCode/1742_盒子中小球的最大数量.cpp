// 1742_盒子中小球的最大数量.cpp
#include "stdafx.h"
ustd

class Solution {
    int digitSum(int num) {
        int result = 0;
        while (num > 0) {
            result += num % 10;
            num /= 10;
        }
        return result;
    }
public:
    int countBalls(int lowLimit, int highLimit) {
        map<int, int> m;
        for (int i = lowLimit; i <= highLimit; i++) {
            m[digitSum(i)]++;
        }
        int maxCount = 0;
        for (const auto& p : m) {
            maxCount = max(maxCount, p.second);
        }
        return maxCount;
    }
};
