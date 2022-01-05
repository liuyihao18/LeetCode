// 1576_替换所有的问号.cpp
#include "custom.h"
ustd

class Solution {
public:
    string modifyString(string s) {
        char prev{}, next{};
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                prev = i > 0 ? s[i - 1] : 0;
                next = i + 1 < s.size() ? s[i + 1] : 0;
                char& c = s[i];
                for (c = 'a'; c <= 'z'; c++) {
                    if (c != prev && c != next) {
                        break;
                    }
                }
            }
        }
        return s;
    }
};
