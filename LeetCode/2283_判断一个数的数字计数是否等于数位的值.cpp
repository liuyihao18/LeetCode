// 2283_判断一个数的数字计数是否等于数位的值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool digitCount(string num) {
        vector<int> counts(10, 0);
        for (auto c : num) {
            counts[c - '0']++;
        }
        string temp;
        for (auto count : counts) {
            temp += count + '0';
        }
        return num == temp.substr(0, num.size());
    }
};
