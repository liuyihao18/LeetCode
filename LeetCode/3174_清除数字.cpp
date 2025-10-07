// 3174_Çå³ıÊı×Ö.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string clearDigits(string s) {
        for (auto iter = s.begin(); iter != s.end(); iter) {
            if (isdigit(*iter)) {
                --iter;
                iter = s.erase(iter);
                iter = s.erase(iter);
            }
            else {
                ++iter;
            }
        }
        return s;
    }
};
