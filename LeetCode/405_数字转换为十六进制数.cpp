// 405_数字转换为十六进制数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        if (num == -2147483648) {
            return "80000000";
        }
        bool negative = num < 0;
        num = negative ? -num : num;
        string result;
        const char remainder2hex[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
        while (num) {
            int remainder = num % 16;
            if (negative) remainder = 15 - remainder;
            result.push_back(remainder2hex[remainder]);
            num /= 16;
        }
        reverse(result.begin(), result.end());
        if (negative) {
            ++*result.rbegin();
            if (*result.rbegin() == '9' + 1) {
                *result.rbegin() = 'a';
            }
            bool carry = false;
            for (auto iter = result.rbegin(); iter != result.rend(); ++iter) {
                if (carry) {
                    ++*iter;
                    if (*iter == '9' + 1) {
                        *iter = 'a';
                    }
                    carry = false;
                }
                if (*iter == 'f' + 1) {
                    carry = true;
                    *iter = '0';
                }
            }
            if (carry) {
                result.insert(result.begin(), '1');
                carry = false;
            }
            while (result.size() != 8) {
                result.insert(result.begin(), 'f');
            }
        }
        return result;
    }
};