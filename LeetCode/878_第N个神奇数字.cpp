// 878_第N个神奇数字.cpp
#include "stdafx.h"
ustd

class Solution {
    int gcd(int a, int b) {
        while (b > 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
    long long kth(long long num, long long a, long long b, long long c, bool& ok) {
        ok = (num % a == 0 || num % b == 0);
        if (!ok) {
            num = max(num / a * a, num / b * b);
        }
        return num / a + num / b - num / c;
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long remainder = 1000000007;
        long long c = lcm(a, b);
        long long right = static_cast<long long>(max(a, b)) * n + 1;
        long long left = static_cast<long long>(min(a, b));
        while (left < right) {
            long long mid = (left + right) / 2;
            bool ok;
            long long k = kth(mid, a, b, c, ok);
            if (k == n && ok) {
                return static_cast<int>(mid % remainder);
            }
            else if (k < n) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return -1;
    }
};
