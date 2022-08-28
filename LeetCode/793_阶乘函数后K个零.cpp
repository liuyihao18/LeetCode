// 793_½×³Ëº¯ÊýºóK¸öÁã.cpp
#include "custom.h"
ustd

class Solution {
public:
    int zeta(long long x) {
        int res = 0;
        while (x > 0) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }

    long long help(int k) {
        long long r = 5LL * k;
        long long l = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (zeta(mid) < k) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return r + 1;
    }

    int preimageSizeFZF(int k) {
        return help(k + 1) - help(k);
    }
};
