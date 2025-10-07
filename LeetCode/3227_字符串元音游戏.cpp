// 3227_×Ö·û´®ÔªÒôÓÎÏ·.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool doesAliceWin(string s) {
        return find_if(s.begin(), s.end(), [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
            }) != s.end();
    }
};
