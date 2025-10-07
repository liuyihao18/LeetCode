// 793_½×³Ëº¯ÊýºóK¸öÁã.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int zeta(long long x) {
        long long res = 0;
        while (x > 0) {
            res += x / 5;
            x /= 5;
        }
        return static_cast<int>(res);
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
        return static_cast<int>(help(k + 1) - help(k));
    }
};
