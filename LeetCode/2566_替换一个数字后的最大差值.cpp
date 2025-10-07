// 2566_替换一个数字后的最大差值.cpp
#include "stdafx.h"
ustd

class Solution {
    int replace(int num, int src, int des) {
        string s = to_string(num);
        for (char& c : s) {
            if (c == src + '0') {
                c = des + '0';
            }
        }
        return stoi(s);
    }
public:
    int minMaxDifference(int num) {
        int minimum = replace(num, to_string(num)[0] - '0', 0);
        int maximum = num;
        for (auto c : to_string(num)) {
            if (c != '9') {
                maximum = replace(num, c - '0', 9);
                break;
            }
        }
        return maximum - minimum;
    }
};
