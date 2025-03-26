// 2829_k-avoiding数组的最小总和.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0, size = 0;
        for (int i = 1; 2 * i <= k && size < n; i++) {
            sum += i;
            size++;
        }
        for (int i = k; size < n; i++) {
            sum += i;
            size++;
        }
        return sum;
    }
};
