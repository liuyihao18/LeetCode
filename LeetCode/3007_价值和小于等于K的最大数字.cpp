// 3007_价值和小于等于K的最大数字.cpp
#include "custom.h"
ustd

class Solution {
    long long getAccumulateValue(long long num, int x) {
        long long res = 0;
        // y <= 64 - __builtin_clzll(num)
        for (int y = x; y <= 62; y += x) {
            long long period = 1LL << y;
            res += period / 2 * (num / period);
            if (num % period >= period / 2) {
                res += num % period - (period / 2 - 1);
            }
        }
        return res;
    }

public:
    long long findMaximumNumber(long long k, int x) {
        long long l = 1, r = (k + 1) << x;
        while (l < r) {
            long long m = (l + r + 1) / 2;
            if (getAccumulateValue(m, x) > k) {
                r = m - 1;
            }
            else {
                l = m;
            }
        }
        return l;
    }
};
