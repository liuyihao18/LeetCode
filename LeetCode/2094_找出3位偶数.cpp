// 2094_ÕÒ³ö3Î»Å¼Êý.cpp
#include "stdafx.h"
ustd

#define SOLUTION_2

#if defined(SOLUTION_1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        size_t n = digits.size();
        set<int> results;
        for (size_t i = 0; i < n; i++) {
            if (digits[i] == 0) {
                continue;
            }
            for (size_t j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                for (size_t k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0) {
                        results.insert(num);
                    }
                }
            }
        }
        return vector<int>(results.begin(), results.end());
    }
};
#elif defined(SOLUTION_2)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        size_t n = digits.size();
        vector<int> counts(10, 0);
        for (size_t i = 0; i < digits.size(); i++) {
            counts[digits[i]]++;
        }
        auto check = [&counts](int num) -> bool
            {
                int digits[3] = { num / 100, num % 100 / 10, num % 10 };
                bool flag = true;
                for (size_t i = 0; i < 3; i++) {
                    flag = (--counts[digits[i]] >= 0) && flag;
                }
                for (size_t i = 0; i < 3; i++) {
                    ++counts[digits[i]];
                }
                return flag;
            };
        vector<int> results;
        for (int num = 100; num < 1000; num += 2) {
            if (check(num)) {
                results.push_back(num);
            }
        }
        return results;
    }
};
#endif
