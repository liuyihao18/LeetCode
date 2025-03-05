// 1328_ÆÆ»µ»ØÎÄ´®.cpp
#include "custom.h"
ustd

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() <= 1) {
            return "";
        }
        for (size_t i = 0; 2 * i + 1 < palindrome.size(); i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome.back()++;
        return palindrome;
    }
};
