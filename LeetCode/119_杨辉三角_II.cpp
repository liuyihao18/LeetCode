// 119_Ñî»ÔÈý½Ç_II.cpp
#include "stdafx.h"
ustd

class Solution {
private:
    long long C(long long m, long long n) {
        if (m == 0) {
            return 1;
        }
        if (n > m / 2) {
            n = m - n;
        }
        long long res = 1;
        for (long long i = 0; i < n; i++) {
            res *= (m - i);
            res /= i + 1;
        }
        return res;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        for (int i = 0; i <= rowIndex; i++) {
            row[i] = static_cast<int>(C(rowIndex, i));
        }
        return row;
    }
};
