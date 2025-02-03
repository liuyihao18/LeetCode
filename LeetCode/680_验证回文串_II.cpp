// 680_验证回文串_II.cpp
#include "custom.h"
ustd

class Solution {
    bool _validPalindrome(const string& s, size_t i, size_t j) {
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            }
            else {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(const string& s) {
        size_t i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            }
            else {
                return _validPalindrome(s, i + 1, j) || _validPalindrome(s, i, j - 1);
            }
        }
        return true;
    }
};
