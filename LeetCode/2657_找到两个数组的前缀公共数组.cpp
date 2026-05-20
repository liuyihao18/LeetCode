// 2657_找到两个数组的前缀公共数组.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> findThePrefixCommonArray(const vector<int>& A, const vector<int>& B) {
        uint64_t bitmapA = 0, bitmapB = 0;
        const int n = static_cast<int>(A.size());
        vector<int> results(n, 0);
        for (int i = 0; i < n; i++)
        {
            bitmapA |= 1ULL << A[i];
            bitmapB |= 1ULL << B[i];
            results[i] = std::popcount(bitmapA & bitmapB);
        }
        return results;
    }
};
