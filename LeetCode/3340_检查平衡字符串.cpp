// 3340_���ƽ���ַ���.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool isBalanced(string num) {
        int sum = 0;
        bool add = true;
        for (auto c : num) {
            if (add) {
                sum += c - '0';
            }
            else {
                sum -= c - '0';
            }
            add = !add;
        }
        return sum == 0;
    }
};
