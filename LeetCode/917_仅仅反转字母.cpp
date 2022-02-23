// 917_仅仅反转字母.cpp
#include "custom.h"
ustd

class Solution {
public:
    string reverseOnlyLetters(string s) {
        if (s.size() == 0) {
            return "";
        }
        size_t i = 0;
        size_t j = s.size() - 1;
        while (i < j) {
            while (!isalpha(s[i]) && i < j) {
                i++;
            }
            while (!isalpha(s[j]) && i < j) {
                j--;
            }
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
