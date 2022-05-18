// 668_乘法表中第k小的数.cpp
#include "custom.h"
ustd

// TLE
class Solution {
    int getCount(int num, int m, int n) {
        int count = 0;
        int half = static_cast<int>(sqrt(num));
        for (int i = 1; i <= half; i++) {
            if (num % i == 0) {
                int a = i;
                int b = num / i;
                if (a == b && half <= m && half <= n) {
                    count++;
                    break;
                }
                if (a <= m && b <= n) {
                    count++;
                }
                if (b <= m && a <= n) {
                    count++;
                }
                if (a > m && b > n) {
                    break;
                }
            }
        }
        return count;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int count = 0;
        for (int i = 1; i <= k; i++) {
            count += getCount(i, m, n);
            if (count >= k) {
                return i;
            }
        }
        return -1;
    }
};
/*
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int x = left + (right - left) / 2;
            int count = x / n * n;
            for (int i = x / n + 1; i <= m; ++i) {
                count += x / i;
            }
            if (count >= k) {
                right = x;
            }
            else {
                left = x + 1;
            }
        }
        return left;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/kth-smallest-number-in-multiplication-table/solution/cheng-fa-biao-zhong-di-kxiao-de-shu-by-l-521a/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/