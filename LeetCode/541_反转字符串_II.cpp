// 541_·´×ª×Ö·û´®_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    string reverseStr(string s, int k) {
        size_t n = s.size();
        size_t I = n / k;
        for (size_t i = 0; i < I; i += 2) {
            reverse(s.begin() + i * k, s.begin() + (i + 1) * k);
        }
        if (~I & 1) {
            reverse(s.begin() + I * k, s.end());
        }
        return s;
    }
};
