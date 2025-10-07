// 1945_字符串转化后的各位数字之和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int getLucky(string s, int k) {
        string temp;
        for (auto c : s) {
            temp += to_string(c - 'a' + 1);
        }
        int number = 0;
        while (k > 0) {
            number = 0;
            for (auto c : temp) {
                number += c - '0';
            }
            temp = to_string(number);
            k--;
        }
        return number;
    }
};
