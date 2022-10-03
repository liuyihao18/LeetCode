// 1784_检查二进制字符串字段.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        bool in = false;
        for (auto c : s) {
            if (c == '1') {
                if (!in) {
                    in = true;
                    cnt++;
                }
            }
            else {
                if (in) {
                    in = false;
                }
            }
        }
        return cnt <= 1;
    }
};
