// 1332_删除回文子序列.cpp
#include "stdafx.h"
ustd

class Solution {
    bool isPalindrome(const string& s) {
        auto iter1 = s.begin();
        auto iter2 = s.end();
        --iter2;
        while (iter1 <= iter2) {
            if (*iter1 != *iter2) {
                return false;
            }
            else {
                ++iter1;
                --iter2;
            }
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if (isPalindrome(s)) {
            return 1;
        }
        else {
            return 2;
        }
    }
};
