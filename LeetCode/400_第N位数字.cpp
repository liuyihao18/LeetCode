// 400_µÚNÎ»Êý×Ö.cpp
#include "stdafx.h"
ustd

class Solution {
    vector<int> ranges = { 0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, INT_MAX };
public:
    int findNthDigit(int n) {
        /**
        * 9 + 2 * 90 + 3 * 900 + 4 * 9000...
        long long sum = 0;
        long long base = 9;
        ranges.push_back(0);
        for (int i = 0; sum < INT_MAX; i++) {
            sum += base * (static_cast<long long>(i) + 1);
            base *= 10;
            ranges.push_back(sum);
        }
        */
        auto iter = lower_bound(ranges.begin(), ranges.end(), n);
        int base = static_cast<int>(distance(ranges.begin(), iter));
        int begin_num = 1;
        for (int i = 1; i < base; i++) {
            begin_num *= 10;
        }
        int diff = iter == ranges.begin() ? n : n - (*(iter - 1) + 1);
        int k = diff / base;
        int re = diff % base;
        int target_num = begin_num + k;
        for (int i = 1; i < base - re; i++) {
            target_num /= 10;
        }
        return target_num % 10;
    }
};
