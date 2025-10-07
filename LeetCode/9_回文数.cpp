// 9_»ØÎÄÊı.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool isPalindrome(int x) {
        long long xx = x, yy = 0;
        while (x > 0) {
            yy = yy * 10 + x % 10;
            x /= 10;
        }
        return xx == yy;
    }
};
