// 2116_判断一个括号字符串是否有效.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool canBeValid(string s, string locked) {
        size_t n = s.size();
        if (n & 1) {
            return false;
        }
        int balance1 = 0;
        for (size_t i = 0; i != n; i++) {
            if (s[i] == '(' || locked[i] == '0') {
                balance1++;
            }
            else {
                balance1--;
            }
            if (balance1 < 0) {
                return false;
            }
        }
        int balance2 = 0;
        for (size_t i = n - 1; i != -1; i--) {
            if (s[i] == ')' || locked[i] == '0') {
                balance2++;
            }
            else {
                balance2--;
            }
            if (balance2 < 0) {
                return false;
            }
        }
        return true;
    }
};
