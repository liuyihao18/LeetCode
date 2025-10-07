// 921_使括号有效的最少添加.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int result = 0;
        for (auto c : s) {
            if (c == '(') {
                if (cnt < 0) {
                    result += -cnt;
                    cnt = 0;
                }
                cnt++;
            }
            else {
                cnt--;
            }
        }
        result += cnt > 0 ? cnt : -cnt;
        return result;
    }
};
