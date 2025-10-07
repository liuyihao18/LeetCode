// 670_×î´ó½»»».cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        vector<int> maximum(digits.size(), 0);
        int maxNum = 0;
        for (size_t i = 0; i < digits.size(); i++) {
            maximum[i] = maxNum;
            maxNum = max(maxNum, digits[i]);
        }
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; i--) {
            if (maximum[i] > digits[i]) {
                for (size_t j = 0; j < digits.size(); j++) {
                    if (digits[j] == maximum[i]) {
                        swap(digits[j], digits[i]);
                    }
                }
                break;
            }
        }
        int result = 0;
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; i--) {
            result = result * 10 + digits[i];
        }
        return result;
    }
};
