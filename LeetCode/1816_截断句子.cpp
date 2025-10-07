// 1816_½Ø¶Ï¾ä×Ó.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string truncateSentence(const string& s, int k) {
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (--k == 0) {
                    return s.substr(0, i);
                }
            }
        }
        return s;
    }
};
